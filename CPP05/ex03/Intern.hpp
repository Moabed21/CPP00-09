#pragma once
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern(/* args */);
		AForm * makeForm(std::string name,std::string target);
		Intern( const Intern& copy );
		Intern &operator=( const Intern& copy);
		~Intern();
};
