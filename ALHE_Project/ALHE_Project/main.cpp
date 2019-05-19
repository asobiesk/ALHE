#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <chrono>

#include "Chromosome.h"
#include "Algorithms.h"

int main()
{

	auto start = std::chrono::system_clock::now();
	for (int i = 0; i < 27; ++i)
		bruteforce(i);
	auto end = std::chrono::system_clock::now();
	auto elapsed = end - start;
	std::cout << "BruteForce: "<<elapsed.count() << '\n';

	start = std::chrono::system_clock::now();
	for (int i = 0; i < 27; ++i)
		optimalAlgorithm(i);
	end = std::chrono::system_clock::now();
	elapsed = end - start;
	std::cout << "optymalny: "<<elapsed.count() << '\n';

	/*auto start = std::chrono::system_clock::now();
	for (int i = 0; i < 27; ++i)
		//TODO EWOLUCYJNY
	auto end = std::chrono::system_clock::now();
	auto elapsed = end - start;
	std::cout << "ewolucyjny: " << elapsed.count() << '\n';
	*/
	getchar();
}