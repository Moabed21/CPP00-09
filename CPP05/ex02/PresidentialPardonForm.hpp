#pragma once
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string target;

	protected:
		virtual void executeAction() const;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		virtual ~PresidentialPardonForm();

		const std::string &getTarget() const;
};
