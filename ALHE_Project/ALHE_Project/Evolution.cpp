#include "Evolution.h"
#include <iostream>


Evolution::Evolution(int value)
{
	aValue = value;
	population = Population(aValue);
}


Evolution::~Evolution()
{
}

void Evolution::startAlgorithmDebug()
{
	std::cout << "Zaczynam algosa..." << std::endl;
	population.generateStartPopulation();
	int counter = 0;
	population.print();
	while (!population.stopCond() && counter != STEPSLIMIT)
	{
		population.cross();		
		population.mutate();
		population.chooseBest();	
		std::cout << "Krok " << counter << std::endl;
		std::cout << "Naj wynik: " << population.getBest().calculateCost(aValue)<<std::endl;
		population.shufflePopulation();
		population.print();

		++counter;
	}

	if (population.getBest().calculateCost(aValue) != 0)
	{
		std::cout << "Nie znaleziono optymalnego rozwiazania w limicie krokow" << std::endl;
		std::cout << "Rozwi¹zanie: ";
		population.getBest().print();
	}
	std::cout << "Znalaz³em rozwi¹zanie w " << counter << " krokach.";
	std::cout << "Rozwi¹zanie: ";
	population.getBest().print();
}

Chromosome Evolution::startAlgorithm()
{
	population.generateStartPopulation();
	int counter = 0;
	while (!population.stopCond() && counter != STEPSLIMIT)
	{

		population.cross();
		population.mutate();
		population.chooseBest();		
		population.shufflePopulation();
		++counter;	
	}

	return population.getBest();

}
