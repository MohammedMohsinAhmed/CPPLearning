Source: https://www.youtube.com/watch?v=ksJ9bdSX5Yo

source.cpp sent to the preprocessor which processes statements starting with #

This creates source.i, which is sent to the compiler

Compiler creates either assembly or binary format of code

Then an assembler like asm takes generated source.s and generates the machine code specific to your architecture

This creates an object/binary file, the source.o

Final stage is the linker stage, which brings other .o files and glues these together to create the final .exe file

2 types of linking:
- static: 
- dynamic files: for shared files that are dynamically loaded into the program. These can be loaded dynamically at runtime

Undefined reference usually means smth is wrong in the linker

Finally we get the source.exe which we can run via ./source.exe

Apply preprocessor stages, so we can see how included code is copy pasted into the main file
g++ -E main.cpp

The compiler phase parses the code, building a syntax tree
You can view the graph created using:
g++ -fdump-tree-all-graph -g main.cpp source.cpp
and visualising the generated .dot files
This tree can be used to check for things like syntax problems
Compiler then generates code. It walks through the syntax tree and breaks them down into assembly instructions
These are a textural representation of machine code

To view resulting assembly:
g++ -S main.cpp
Generates the main.s file which is in assembly

The assembler converts the assembly into .o code, the object code
The -c flag compiles and assembles without linking
g++ -c main.cpp

To link object files, use:
g++ &lt;object files/cpp files&gt; -o main
To create the source

You can read object files using 
objdump -t &lt;object file&gt;

Consider the code #include &lt;iostream&gt;
Our compiler can include this library in our code with no issue. But how can we make c++ find the library from scratch?

Use the -l flag like in this example:
g++ sfml.cpp -o prog -lsfml-system -lsfml-window -lsfml-graphics
Which asks g++'s linker to include the provided libraries
Package manager sorts the finding of the libraries in memory for us

To give the exact path however, in case, we use the -L flag: 

g++ sfml.cpp -o prog -lsfml-system -lsfml-window -lsfml-graphics -L/usr/lib/x86_64-linux-gnu/

