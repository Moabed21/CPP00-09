#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
private:
	std::map<std::string, double> _rates; // date "YYYY-MM-DD" -> exchange rate

	static bool	isValidDate(const std::string &date);
	static bool	isNumber(const std::string &str);
	static std::string	trim(const std::string &str);

	void	processLine(const std::string &line) const;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void	loadDatabase(const std::string &path);
	void	processInput(const std::string &path) const;
};

#endif
