#pragma once
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		std::string target;

	protected:
		virtual void executeAction() const;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		virtual ~ShrubberyCreationForm();

		const std::string &getTarget() const;
};


