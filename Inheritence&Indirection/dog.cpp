#include <iostream>
#include "dog.h"

Dog::Dog(int age, std::string breed) : Animal(age), breed_{ breed } {};

Dog::~Dog() { std::cout << "Dog Destructor" << '\n'; }

std::string Dog::Noise() const {
	return "Woof";
}

std::string Dog::VNoise() const {
	return "Overriding virtual with woof";
}