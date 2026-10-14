#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : name("Default"), isSigned(false), signGrade(150), executeGrade(150)
{
}

Form::Form(const std::string &name, int signGrade, int executeGrade)
    : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (this->signGrade < 1 || this->executeGrade < 1)
        throw Form::GradeTooHighException();
    if (this->signGrade > 150 || this->executeGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade)
{
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

Form::~Form()
{
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade Too Low";
}

const std::string &Form::getName() const
{
    return this->name;
}

bool Form::getIsSigned() const
{
    return this->isSigned;
}

int Form::getSignGrade() const
{
    return this->signGrade;
}

int Form::getExecuteGrade() const
{
    return this->executeGrade;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= this->signGrade)
    {
        this->isSigned = true;
    }
    else
    {
        throw Form::GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &o, const Form &obj)
{
    o << "Form " << obj.getName()
      << ", sign grade " << obj.getSignGrade()
      << ", execute grade " << obj.getExecuteGrade()
      << ", signed: " << (obj.getIsSigned() ? "yes" : "no") << ".";
    return o;
}