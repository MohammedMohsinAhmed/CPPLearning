#pragma once

#include "Animal.h"
#include <string>

class Dog : public Animal {
private:
	int age_;
	std::string breed_;
public:
	Dog(int age, std::string breed);
	~Dog();
	std::string Noise() const;
	std::string VNoise() const;
};
