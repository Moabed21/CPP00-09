#pragma once
#include <iostream>
#include "AForm.hpp"
class AForm;
class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(int grade, const std::string &name);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		void	incrementGrade();
		void	decrementGrade();

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		int getGrade() const;
		void	setGrade(int _grade);
		const std::string &getName() const;
		void signForm(AForm &form);
		void executeForm(AForm const & form) const;
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &obj);
