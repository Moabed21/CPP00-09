#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int random = rand() % 3;

	if (random == 0)
	{
		std::cout<<"A Generated\n";
		return(new A());
	}
	else if(random == 1)
	{
		std::cout<<"B Generated\n";
		return(new B());
	}
	else if(random == 2)
	{
		std::cout<<"C Generated\n";
		return(new C());
	}
	return (NULL);
}

void identify(Base* p)
{
	if ((dynamic_cast<A*> (p)) )
		std::cout<<"A\n";
	else if ((dynamic_cast<B*> (p)) )
		std::cout<<"B\n";
	else if ((dynamic_cast<C*> (p)) )
		std::cout<<"C\n";
}

void identify(Base& p)
{
	try {
        dynamic_cast<A&>(p);
        std::cout << "A\n";
    } 
	catch(...){}
	try {
        dynamic_cast<B&>(p);
        std::cout << "B\n";
    } 
	catch(...){}
	try {
        // Attempting to cast to a reference will throw std:: bad_cast if it fails
        dynamic_cast<C&>(p);
        std::cout << "C\n";
    } 
	catch (...){}
	// for educational purposes :)
	// catch(const std::bad_cast&){ std::cerr <<"Errorrrrrrrrrrrrr\n";}
}
int main()
{
	srand(time(0));

	for (int i = 0; i < 5; ++i)
	{
		std::cout << "--- Test " << (i + 1) << " ---" << std::endl;
		Base *obj = generate();
		if (obj)
		{
			std::cout << "Identify via pointer:   ";
			identify(obj);
			std::cout << "Identify via reference: ";
			identify(*obj);
			delete obj;
		}
	}

	return 0;
}
