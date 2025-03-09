#include <iostream>
#include <vector>

// compile with g++ -fno-elide-constructors -o main .\RVOandNRVO.cpp

class Base
{
public:
    Base()
    {
        std::cout << "Constructor of Base" << '\n';
    }

    Base(const Base &)
    {
        std::cout << "Copy constructor of Base" << '\n';
    }

    ~Base()
    {
        std::cout << "Base has been destroyed" << '\n';
    }
};

Base func()
{
    return Base();
}

int main()
{
    Base b = func();
}