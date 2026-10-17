when you write :   Animal *ptr = new Cat();
Dynamic Type (Runtime): The actual object created on the heap is a Cat.
Static Type (Compile-Time): The pointer ptr is an Animal*.

The C++ compiler is strictly static. When compiling ptr->something(), the compiler checks only what is declared inside Animal.