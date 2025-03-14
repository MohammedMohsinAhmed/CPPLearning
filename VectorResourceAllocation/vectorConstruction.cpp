#include <vector>
#include <string>
#include <iostream>

using std::vector;

class Person {
private:
	std::string name_;
public:
	Person(std::string name) : name_{ name } { std::cout << "Constructing " << name_ << '\n'; };
	Person(const Person& person) : name_{ person.getName() } { std::cout << "Copy constructing " << name_ << '\n'; };
	Person& operator=(const Person& person) { 
		name_ = person.getName();
		std::cout << "Copy assignment " << name_ << '\n'; 
	};
	~Person() { std::cout << "Destructing " << name_ << '\n'; }

	std::string getName() const { return name_; }

};

int main() {
	Person p = Person("Fred");

	vector<Person> people;

	people.push_back(p);

	// Constr... Fred				: Line 24, creating Person instance
	// Copy Constr.. Fred			: Line 28, deep copying our Person instance into the array

	std::cout << "------------------------------" << '\n';

	people.push_back(Person("Dan"));

	// Constr... Dan				: 36, we construct a temporary Person instance Dan
	// Copy Constr.. Dan			: ^, Currently, vector is size 1. This cant fit the new Dan instance. 
	//								      ... Allocate double the size of the vector elsewhere is memory and copy the Dan instance to that vector
	// Copy Constr.. Fred			: ^ Fred instance must also move to this new vector
	// Destr... Fred				: ^ Destroy the instance of Fred in the previous vector
	// Destr... Dan					: ^ Finally, destroy the temporary Dan instance created inside the brackets

	std::cout << "------------------------------" << '\n';

	// Destr... Fred				: 50: After leaving the scope of people, we must destruct what's inside it. First destruct Fred
	// Destr... Dan					: ^: Then Dan...
	// Destr... Fred				: ^ Finally destruct the instance of Person we created on 24
}