const has many meanings. In these cases it prevents human error and allows the compiler to perform optimisations:

# When initialising and a variable:
<em> const int a </em> <br>
This is a promise to the compiler that the value in a will not change. If you try changing the value in a, you'll get a compiler error

# When declaring a member function
<em> int Something const {do something....} </em> <br>
This is a promise to the compiler that this member function will not change any member value of the instance

# When passing an object by reference
<em> void someFunction(someObject const& o) </em> <br>
This allows us to pass an object into the function with a reference (thanks to &), avoiding potentially expensive copy semantics, and prevents this object being changed (const)
By passing by reference, we are using the same instance of the object that exists in the scope that called someFunction, but const prevents us making any changes to the objects

# Promise a pointer will not change the location it refers to
<em> int * const intPtr </em> <br>
Here, the const goes after the *, indicating that this is a const pointer. This means that we can change the value the pointer points to, but we cannot change the address the pointer points to. Eg we can do *intPtr = 4, but not intPtr = &anotherVar

# State a pointer is pointing to a const
<em> int const * intPtr </em> <br>
Here, the const comes after the int. This indicates that whatever the pointer is pointing to is const. So we can do intPtr = &anotherVar, but not *intPtr = 5, as we're changing the value at the pointer when we promised it would stay the same




