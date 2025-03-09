In line 27, we call a function that returns a base
If we compile this as usual without the extra flag included in the comment, then as expected we'll only see the message from the default constructor of Base: "Constructor of Base". This is expected

However, under the hood the compiler has actualy performed some optimisation, removing the need to make expensive copies
This was introduced in c++17, and is called "copy elision" (elision meaning omission here)

If we add the flag -fno-elide-constructors then we tell the compiler to not do this optimisation

Now if we compile the code and run we see the following:

Constructor of Base
Copy constructor of Base
Copy constructor of Base

What happened?

Looking at line 22, we construct an instance of base, then return it. 
Since we perform an initialisation in the return (in the wiki this is referred to as "braced-list-init"),
Return uses copy-list-initialisation to construct the return value of the function
In other words, a copy of the object we just created (in Base()) is made and put somewhere in memory *
To be the return value of our function
Our copy constructor defined on 14 has been implicitly called to do this

As for the second copy constructor message, look at 27
We have our returned copy of base as explained in *. b has been initialised (had memory allocated to it)
Now, we need to put the return value of the function into b
This requires yet another copy, again calling the copy constructor we defined

So, in this simple program we've had to perform 2 copies. There must be a better way to do this
This is where copy elision comes in.
The compiler can see that its not necessary to make the 2 copies. Instead, just allocate memory to b, and put the function return value DIRECTLY in this allocated memory. No more copies
This is called return value optimisation or RVO. 
NRVO (named return value optimisation) is very similar, its jsut when we return a named value instead of just Base(), like:

Base b = Base();
return b   <- named value

This is made clearer when we define a destructor with a message:

Constructor of Base
Copy constructor of Base
Base has been destroyed
Copy constructor of Base
Base has been destroyed
Base has been destroyed

Notice we've had to destroy Base 3 times.
First time when leaving func(), the version we created with Base() is destroyed
Then, in the main function, the return value of func and the value of b are in scope
When we leave the function, both are destroyed

