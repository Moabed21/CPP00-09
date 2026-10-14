#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=== Test 1: Valid Bureaucrat and Form Creation ===" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 25);
        Form taxForm("Tax Form 28B", 30, 50);

        std::cout << alice << std::endl;
        std::cout << taxForm << std::endl;

        std::cout << "\nAttempting to sign form..." << std::endl;
        alice.signForm(taxForm);
        std::cout << taxForm << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Bureaucrat Grade Too Low to Sign ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 100);
        Form topSecret("Top Secret Document", 50, 20);

        std::cout << bob << std::endl;
        std::cout << topSecret << std::endl;

        std::cout << "\nBob attempts to sign top secret document..." << std::endl;
        bob.signForm(topSecret);
        std::cout << topSecret << std::endl;

        std::cout << "\nDirect beSigned call (should throw exception):" << std::endl;
        topSecret.beSigned(bob);
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught expected exception from beSigned: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Form Instantiation with Grade Too High (0) ===" << std::endl;
    try
    {
        Form invalidForm("Invalid High Form", 0, 50);
        std::cout << invalidForm << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Form Instantiation with Grade Too Low (151) ===" << std::endl;
    try
    {
        Form invalidForm("Invalid Low Form", -1, -1);
        std::cout << invalidForm << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    return 0;
}