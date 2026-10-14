#include "Intern.hpp"

Intern::Intern(/* args */)
{
}

Intern::Intern( const Intern& copy )
{
    ( void )copy;
}

Intern& Intern::operator=( const Intern& copy)
{
    if ( this != &copy ) {}
    return ( *this );
}

AForm * createShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}
AForm * createRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm*  createPresidential( const std::string& target )
{
    return (new PresidentialPardonForm( target ));
}
AForm * Intern::makeForm(std::string name,std::string target)
{
	std::string list1[] = {"presidential pardon","robotomy request","shrubbery creation"};

	AForm*  ( *list2[] )( const std::string& ) = { createShrubbery, createRobotomy, createPresidential };
	// array of pointers 
    for ( int i = 0; i < 3; i++)
    {
        if ( list1[i] == name )
        {
            std::cout << "Intern creates "<< name<< std::endl;
            return ( list2[i]( target ) );
        }    
    }
	std::cout<<"no type match\n";
	return NULL;
}

Intern::~Intern()
{
}
