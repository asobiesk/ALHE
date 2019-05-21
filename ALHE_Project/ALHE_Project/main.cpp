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
	int value = 10;
	std::cout << "-------------- PRZYKLADOWE ROZWIAZANIE DLA A: " << value << " --------------" << std::endl;
	std::cout << "Bruteforce: " << std::endl;
	Chromosome chrom = bruteforce(value);
	chrom.print();
	chrom.printDivision();

	std::cout << std::endl << "Optymalny: " << std::endl;
	chrom = optimalAlgorithm(value);
	chrom.print();
	chrom.printDivision();

	std::cout << std::endl << "Ewolucyjny: " << std::endl;
	Evolution ev(value);
	chrom = ev.startAlgorithm();
	chrom.print();
	chrom.printDivision();
	std::cout << (chrom.calculateCost(value) == 0 ? "Rozwiazanie optymalne" : "To nie jest najlepsze rozwiazanie") << std::endl;
	
	Evolution ef(value);
	ef.startAlgorithmDebug();


	std::cout << std::endl << std::endl << "-------------- POMIAR CZASU WYKONANIA DLA ROZWIAZYWANIA PROBLEMOW OD 0 DO 26 --------------" << std::endl;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 27; ++i)
		bruteforce(i);
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "bruteforce: " << elapsed.count() / 1000 << "ms  " << elapsed.count() % 1000 << "us \n";

	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 27; ++i)
		optimalAlgorithm(i);
	end = std::chrono::high_resolution_clock::now();
	elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "optymalny: "<<elapsed.count()/1000<<"ms  "<< elapsed.count() % 1000 << "us \n";

	int suma = 0;
	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 27; ++i)
	{
		Evolution ev(i);
		Chromosome chrom = ev.startAlgorithm();
		if (chrom.calculateCost(i) != 0)
			++suma;
	}
	end = std::chrono::high_resolution_clock::now();
	elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "ewolucyjny: " << elapsed.count() / 1000 << "ms  " << elapsed.count() % 1000 << "us \n";
	std::cout << "nie znalazlem rozwiazania w: " << suma << " przypadkach \n";

	getchar();
}