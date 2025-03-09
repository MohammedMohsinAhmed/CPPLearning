const has many meanings. In these cases it prevents human error and allows the compiler to perform optimisations:

1) When initialising and a variable:
const int a
^ This is a promise to the compiler that the value in a will not change. If you try changing the value in a, you'll get a compiler error

2) When declaring a member function
int Something const {do something....}
^ This is a promise to the compiler that this member function will not change any member value of the instance

3) When passing an object by reference
void someFunction(someObject const& o)
^ This allows us to pass an object into the function with a reference (thanks to &), avoiding potentially expensive copy semantics, and prevents this object being changed (const)
By passing by reference, we are using the same instance of the object that exists in the scope that called someFunction, but const prevents us making any changes to the objects
