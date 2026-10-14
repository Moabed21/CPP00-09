why we use try catch? 

- to handle unexpected behaviour or raising an error correctly in a safe way

- Automatic error propagation: Errors can “travel up” the function calls 
automatically until someone knows how to handle them.

- Forces proper handling :If you don’t catch an exception, the program stops → you cannot accidentally ignore critical errors.

- Safer for resources: Constructors, memory allocation, 
files → if something fails, exceptions ensure resources are cleaned properly.

when using throw() "exeption object" is created and stored temporarily in stack or heap,
 stopping the normal flow of the current program, any remaining code in the current block is skipped,

Stack unwinding begins: all local variables in the functions on the call stack between
 the throw point and the nearest matching catch are destroyed (their destructors are called).


