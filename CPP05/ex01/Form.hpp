#pragma once
#include <iostream>
#include <string>

class Bureaucrat; 

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int executeGrade;

    public:
        Form();
        Form(const std::string &name, int signGrade, int executeGrade = 150);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

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

        const std::string &getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        void beSigned(const Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &o, const Form &obj);
