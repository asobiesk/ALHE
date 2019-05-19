#include "Population.h"
#include <algorithm>
#include <iostream>



Population::Population(int value)
{
	best = Chromosome(aValue);
	aValue = value;
}

void Population::generateStartPopulation()
{
	srand(time(0));

	for (int i = 0; i < MAXPOP; ++i)
	{
		Chromosome newChrom(aValue);
		newChrom.generateRandom();
		population.push_back(newChrom);
	}
	chooseBest();
}

Chromosome Population::chooseBest()
{
	Chromosome bestChromByNow = population[0];
	int bestCostByNow = bestChromByNow.calculateCost(aValue);

	for (int i = 1; i < population.size(); ++i)
	{
		int newCost = population[i].calculateCost(aValue);
		if (newCost < bestCostByNow)
		{
			bestCostByNow = newCost;
			bestChromByNow = population[i];
		}
	}
	best = bestChromByNow;
	return bestChromByNow;
}

void Population::cross()
{
	std::vector<Chromosome> children;
	srand(time(0));

	for (int i = 0; i < MAXPOP-1; ++i)
	{
		//Generate children
		Chromosome child(aValue);
		int crossPoint = std::rand() % CHROMLENGHT;
		int j = 0;
		while (j != crossPoint)
		{
			child.chrom.push_back(population[i].chrom[j]);
			++j;
		}
		while (j != MAXPOP)
		{
			child.chrom.push_back(population[i+1].chrom[j]);
			++j;
		}
		children.push_back(child);
	}
	//Select new Population
	std::vector<Chromosome> newPop;
	for (Chromosome c : population)
		newPop.push_back(c);
	for (Chromosome c1 : children)
		newPop.push_back(c1);
	
	std::sort(newPop.begin(), newPop.end());

	for (int i = 0; i < newPop.size() / 2; ++i)
		newPop.pop_back();

	population = newPop;
}

void Population::mutate()
{
	srand(time(0));
	for (Chromosome chromosome : population)
	{
		for (int i = 0; i < CHROMLENGHT; ++i)
		{
			int random = rand() % 100;
			if (random < 5)
				chromosome.chrom[i] = !(chromosome.chrom[i]);
		}
	}
}

bool Population::stopCond()
{
	
	if (best.calculateCost(aValue) == 0)
		return true;
	else
		return false;
}

void Population::print()
{
	std::cout << "Obecna populacja: " << std::endl;
	for (Chromosome c : population)
		c.print();

}

void Population::shufflePopulation()
{
	std::random_shuffle(population.begin(), population.end());
}

Population::~Population()
{
}
