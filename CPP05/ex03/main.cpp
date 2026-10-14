#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{

	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	std::cout << rrf->getName();

	delete rrf;
	std::srand(std::time(NULL));

	Bureaucrat boss("Boss", 1);
	Bureaucrat middle("Manager", 40);
	Bureaucrat intern("Intern", 140);
	Bureaucrat low("Trainee", 150);

	std::cout << "--- Bureaucrats ---" << std::endl;
	std::cout << boss << std::endl;
	std::cout << middle << std::endl;
	std::cout << intern << std::endl;
	std::cout << low << std::endl;

	std::cout << "\n========================================" << std::endl;
	std::cout << "1. Testing ShrubberyCreationForm (sign 145, exec 137)" << std::endl;
	std::cout << "========================================" << std::endl;
	{
		ShrubberyCreationForm shrub("garden");
		std::cout << shrub << std::endl;

		std::cout << "\n* Attempt execute before signing:" << std::endl;
		boss.executeForm(shrub);

		std::cout << "\n* Low bureaucrat attempts to sign (grade 150 > 145):" << std::endl;
		low.signForm(shrub);

		std::cout << "\n* Intern signs (grade 140 <= 145):" << std::endl;
		intern.signForm(shrub);
		std::cout << shrub << std::endl;

		std::cout << "\n* Intern attempts to execute (grade 140 > 137):" << std::endl;
		intern.executeForm(shrub);

		std::cout << "\n* Manager executes (grade 40 <= 137):" << std::endl;
		middle.executeForm(shrub);
	}

	std::cout << "\n========================================" << std::endl;
	std::cout << "2. Testing RobotomyRequestForm (sign 72, exec 45)" << std::endl;
	std::cout << "========================================" << std::endl;
	{
		RobotomyRequestForm robot("Bender");
		std::cout << robot << std::endl;

		std::cout << "\n* Attempt execute before signing:" << std::endl;
		boss.executeForm(robot);

		std::cout << "\n* Intern attempts to sign (grade 140 > 72):" << std::endl;
		intern.signForm(robot);

		std::cout << "\n* Manager signs (grade 40 <= 72):" << std::endl;
		middle.signForm(robot);

		std::cout << "\n* Low bureaucrat attempts to execute (grade 150 > 45):" << std::endl;
		low.executeForm(robot);

		std::cout << "\n* Manager executes multiple times (50% success rate):" << std::endl;
		for (int i = 0; i < 4; ++i)
		{
			middle.executeForm(robot);
		}
	}

	std::cout << "\n========================================" << std::endl;
	std::cout << "3. Testing PresidentialPardonForm (sign 25, exec 5)" << std::endl;
	std::cout << "========================================" << std::endl;
	{
		PresidentialPardonForm pardon("Arthur Dent");
		std::cout << pardon << std::endl;

		std::cout << "\n* Attempt execute before signing:" << std::endl;
		boss.executeForm(pardon);

		std::cout << "\n* Manager attempts to sign (grade 40 > 25):" << std::endl;
		middle.signForm(pardon);

		std::cout << "\n* Boss signs (grade 1 <= 25):" << std::endl;
		boss.signForm(pardon);

		std::cout << "\n* Manager attempts to execute (grade 40 > 5):" << std::endl;
		middle.executeForm(pardon);

		std::cout << "\n* Boss executes (grade 1 <= 5):" << std::endl;
		boss.executeForm(pardon);
	}

	return 0;
}