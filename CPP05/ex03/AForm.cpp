#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : name("Default"), isSigned(false), signGrade(150), executeGrade(150)
{}

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
    : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (this->signGrade < 1 || this->executeGrade < 1)
        throw AForm::GradeTooHighException();
    if (this->signGrade > 150 || this->executeGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm()
{
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade Too Low";
}
const char *AForm::FormIsNotSignedException::what() const throw()
{
    return "Form is not signed";
}
const std::string &AForm::getName() const
{
    return this->name;
}

bool AForm::getIsSigned() const
{
    return this->isSigned;
}

int AForm::getSignGrade() const
{
    return this->signGrade;
}

int AForm::getExecuteGrade() const
{
    return this->executeGrade;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= this->signGrade)
    {
        this->isSigned = true;
    }
    else
    {
        throw AForm::GradeTooLowException();
    }
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!this->isSigned)
        throw AForm::FormIsNotSignedException();
    if (executor.getGrade() > this->executeGrade)
        throw AForm::GradeTooLowException();
    this->executeAction();
}

std::ostream &operator<<(std::ostream &o, const AForm &obj)
{
    o << "Form " << obj.getName()
      << ", sign grade " << obj.getSignGrade()
      << ", execute grade " << obj.getExecuteGrade()
      << ", signed: " << (obj.getIsSigned() ? "yes" : "no") << ".";
    return o;
}