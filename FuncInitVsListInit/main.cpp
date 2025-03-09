#include <chrono>
#include <iostream>
#include <string>
#include "listInit.h"
#include "funcInit.h"

using std::string;

int main() {

	string str = "Herro";

	// Initialisation using function body is almost twice as slow as using initialiser list
	// Reason is because the member variables are created before constructor body runs
	// When using an initialiser list, we only initialise the member string once with "Herro"
	// When using the function to initialise, we initialise twice, first with default value "" then replacing with "Herro"
	//     in the function body

	const auto start1{ std::chrono::high_resolution_clock::now() };
	listInit test1 = listInit(str);
	const auto finish1{ std::chrono::high_resolution_clock::now() };
	const std::chrono::duration<double> time1 = finish1 - start1 ;

	std::cout << time1.count() << '\n';

	const auto start2{ std::chrono::high_resolution_clock::now() };
	funcInit test2 = funcInit(str);
	const auto finish2{ std::chrono::high_resolution_clock::now() };
	const std::chrono::duration<double> time2 = finish2 - start2;

	std::cout << time2.count() << '\n';


}