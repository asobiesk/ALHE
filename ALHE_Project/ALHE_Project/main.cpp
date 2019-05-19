#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <chrono>

#include "Chromosome.h"
#include "Algorithms.h"
#include "Evolution.h"

int main()
{

	auto start = std::chrono::system_clock::now();
	for (int i = 0; i < 27; ++i)
		bruteforce(i);
	auto end = std::chrono::system_clock::now();
	auto elapsed = end - start;
	std::cout << "bruteforce: "<<elapsed.count() << '\n';

	start = std::chrono::system_clock::now();
	for (int i = 0; i < 27; ++i)
		optimalAlgorithm(i);
	end = std::chrono::system_clock::now();
	elapsed = end - start;
	std::cout << "optymalny: "<<elapsed.count() << '\n';

	int suma = 0;
	start = std::chrono::system_clock::now();
	for (int i = 0; i < 27; ++i)
	{
		Evolution ev(i);
		Chromosome chrom = ev.startAlgorithm();
		if (chrom.calculateCost(i) != 0)
			++suma;
	}
	end = std::chrono::system_clock::now();
	elapsed = end - start;
	std::cout << "ewolucyjny: " << elapsed.count() << '\n';
	std::cout << "nie znalazlem rozwiazania w: " << suma << " przypadkach \n";
	
	getchar();
}