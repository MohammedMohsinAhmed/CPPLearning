#pragma once

#include <string>

class Animal {
private:
	int age_;
public:
	Animal(int age);
	virtual ~Animal();
	std::string Noise() const;
	virtual std::string VNoise() const;
};