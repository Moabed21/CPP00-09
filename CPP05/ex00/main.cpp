#include "Bureaucrat.hpp"

int main()
{
    // Important: Any code in the try block after the throw statement will never run.
    std::cout << "=== Test 1: Valid Bureaucrat and Increment/Decrement ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 3);
        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;

        bob.decrementGrade();
        std::cout << "After decrement: " << bob << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    // After catch, program continues normally.
    std::cout << "\n=== Test 2: Instantiation with Grade Too High (0) ===" << std::endl;
    try
    {

        Bureaucrat alice("Alice", 0);
        std::cout << alice << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Instantiation with Grade Too Low (151) ===" << std::endl;
    try
    {
        Bureaucrat charlie("Charlie", 151);
        std::cout << charlie << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Incrementing Grade 1 beyond limit ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        std::cout << boss << std::endl;
        boss.incrementGrade();
        std::cout << "This line will NOT print: " << boss << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Decrementing Grade 150 beyond limit ===" << std::endl;
    try
    {
        Bureaucrat intern("Intern", 150);
        std::cout << intern << std::endl;
        intern.decrementGrade();
        std::cout << "This line will NOT print: " << intern << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    return 0;
}