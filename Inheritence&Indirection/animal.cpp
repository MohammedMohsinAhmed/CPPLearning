#include "animal.h"
#include <iostream>

Animal::Animal(int age) : age_{ age } {};

Animal::~Animal() { std::cout << "Animal Destructor" << '\n'; }

std::string Animal::Noise() const {
	return "Generic Animal Sound";
}

std::string Animal::VNoise() const {
	return "Generic virtual Animal Sound";
}

