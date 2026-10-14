#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), target(other.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const std::string &ShrubberyCreationForm::getTarget() const
{
	return this->target;
}

void ShrubberyCreationForm::executeAction() const
{
	std::string filename = this->target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open())
		return;

	file << "       _-_\n"
	     << "    /~~   ~~\\\n"
	     << " /~~         ~~\\\n"
	     << "{               }\n"
	     << " \\  _-     -_  /\n"
	     << "   ~  \\\\ //  ~\n"
	     << "_- -   | | _- _\n"
	     << "  _ -  | |   -_\n"
	     << "      // \\\\\n"
	     << "\n"
	     << "         v .   ._, |_  .,\n"
	     << "      `-._\\/  .  \\ /    |/_\n"
	     << "          \\\\  _\\, y | \\//\n"
	     << "    _\\_.___\\\\, \\\\/ -.\\||\n"
	     << "      `7-,--.`._||  / / ,\n"
	     << "      /'     `-. `./ / |/_.'\n"
	     << "                |    |//\n"
	     << "                |_    /\n"
	     << "                |-   |\n"
	     << "                |   =|\n"
	     << "                |    |\n"
	     << "---------------/ ,  . \\--------._\n";
	file.close();
}
