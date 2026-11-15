#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _rates(other._rates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_rates = other._rates;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

/* ---------- helpers ---------- */

std::string BitcoinExchange::trim(const std::string &str)
{
	std::string::size_type start = str.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return "";
	std::string::size_type end = str.find_last_not_of(" \t\r\n");
	return str.substr(start, end - start + 1);
}

// Strict "YYYY-MM-DD" with a real calendar day (leap years included).
bool BitcoinExchange::isValidDate(const std::string &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (std::string::size_type i = 0; i < date.size(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (date[i] < '0' || date[i] > '9')
			return false;
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12 || day < 1)
		return false;
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	if (month == 2 && leap)
		return day <= 29;
	return day <= daysInMonth[month - 1];
}

// Optional sign, digits, optional '.' followed by digits. Rejects "", ".", "1.", "inf", "nan", "1e3".
bool BitcoinExchange::isNumber(const std::string &str)
{
	std::string::size_type i = 0;
	if (i < str.size() && (str[i] == '-' || str[i] == '+'))
		++i;
	std::string::size_type digitsBefore = 0;
	while (i < str.size() && str[i] >= '0' && str[i] <= '9')
	{
		++i;
		++digitsBefore;
	}
	if (digitsBefore == 0)
		return false;
	if (i < str.size() && str[i] == '.')
	{
		++i;
		std::string::size_type digitsAfter = 0;
		while (i < str.size() && str[i] >= '0' && str[i] <= '9')
		{
			++i;
			++digitsAfter;
		}
		if (digitsAfter == 0)
			return false;
	}
	return i == str.size();
}

/* ---------- database ---------- */

void BitcoinExchange::loadDatabase(const std::string &path)
{
	std::ifstream file(path.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database.");

	std::string line;
	if (!std::getline(file, line) || trim(line) != "date,exchange_rate")
		throw std::runtime_error("Error: invalid database header.");

	while (std::getline(file, line))
	{
		line = trim(line);
		if (line.empty())
			continue;
		std::string::size_type comma = line.find(',');
		if (comma == std::string::npos)
			throw std::runtime_error("Error: invalid database line => " + line);
		std::string date = line.substr(0, comma);
		std::string rate = line.substr(comma + 1);
		if (!isValidDate(date) || !isNumber(rate))
			throw std::runtime_error("Error: invalid database line => " + line);
		_rates[date] = std::strtod(rate.c_str(), NULL);
	}
	if (_rates.empty())
		throw std::runtime_error("Error: database is empty.");
}

/* ---------- input ---------- */

void BitcoinExchange::processLine(const std::string &line) const
{
	std::string::size_type sep = line.find(" | ");
	if (sep == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}
	std::string date = line.substr(0, sep);
	std::string valueStr = line.substr(sep + 3);

	if (!isValidDate(date))
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return;
	}
	if (!isNumber(valueStr))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}
	double value = std::strtod(valueStr.c_str(), NULL);
	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return;
	}
	if (value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return;
	}

	// First entry strictly after `date`; the one before it is the closest lower-or-equal date.
	std::map<std::string, double>::const_iterator it = _rates.upper_bound(date);
	if (it == _rates.begin())
	{
		std::cout << "Error: bad input => " << date << std::endl; // earlier than any DB date
		return;
	}
	--it;
	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}

void BitcoinExchange::processInput(const std::string &path) const
{
	std::ifstream file(path.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string line;
	if (!std::getline(file, line))
		throw std::runtime_error("Error: empty file.");

	// Default precision (6) turns 47115930 into 4.71159e+07; 10 digits keeps it whole
	// while still printing 0.3 * 3 as 0.9.
	std::streamsize oldPrecision = std::cout.precision(10);

	line = trim(line);
	if (line != "date | value")
		processLine(line); // no header: treat first line as data

	while (std::getline(file, line))
	{
		line = trim(line);
		if (line.empty())
			continue;
		processLine(line);
	}
	std::cout.precision(oldPrecision);
}
