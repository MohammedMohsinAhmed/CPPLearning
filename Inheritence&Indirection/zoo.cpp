#include <iostream>
#include "animal.h"
#include "dog.h"

int main() {
	Dog doggo = Dog(1, "kendrick lmao");

	// Our Dog is a derived class of Animal
	std::cout << doggo.Noise() << '\n';

	// Try different types of pointers to see what happens when we call noise
	Animal* animalPtr = &doggo;
	Animal& animalRef = doggo;
	Dog* dogPtr = &doggo;
	Dog& dogRef = doggo;

	// By getting a pointer to dog casted as an animal, we end up calling the base classes Noise function
	std::cout << "Regular method: " << '\n';
	std::cout << animalPtr->Noise() << '\n';
	std::cout << animalRef.Noise() << '\n';
	std::cout << dogPtr->Noise() << '\n';
	std::cout << dogRef.Noise() << '\n';

	// We shouldnt try using a Dog pointer for an animal though, as the animal doesnt have all of Dogs properties & methods
	
	// What if we try use our pointers to call a virtual method overriden by the derived class Dog?
	// Regardless of the pointer type, we end up calling Dogs version of VNoise
	// When a method has the virtual keyword, the type of reference/pointer being used to call the method doesnt matter
	// Only the most recent override of the method is called
	std::cout << "Virtual method that Dog overrides: " << '\n';
	std::cout << animalPtr->VNoise() << '\n';
	std::cout << animalRef.VNoise() << '\n';
	std::cout << dogPtr->VNoise() << '\n';
	std::cout << dogRef.VNoise() << '\n';

	// If you have a virtual method, you should then make your destructor virtual as well
	// This is because, its possible we could call the animal destructor for a Dog instance, potentially causing a memory leak:
	Animal* dogAni = new Dog(1, "Daniel Shebortneck");
	std::cout << "Deleting dogAni" << '\n';
	delete dogAni;
	std::cout << "Done deleting dogAni" << '\n';

	// Looking at the console we see that the Animal destructor was called
	// You can compare the behaviour when we make the animal destructor virtual, when we make it virtual both dog and animal are destructed

	// Notice how the last 2 console messages are the destruction of an animal and dog
	// This is becauase we called the animal constuctor creating our doggo earlier. Both the animal and dog had to be destructed

}