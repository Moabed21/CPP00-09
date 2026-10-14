#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), target(other.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

const std::string &RobotomyRequestForm::getTarget() const
{
	return this->target;
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "* DRILLING NOISES: BZZZZZZT! DRILL DRILL DRILL! *" << std::endl;
	if (std::rand() % 2 == 0)
	{
		std::cout << this->target << " has been robotomized successfully!" << std::endl;
	}
	else
	{
		std::cout << "The robotomy on " << this->target << " failed." << std::endl;
	}
}