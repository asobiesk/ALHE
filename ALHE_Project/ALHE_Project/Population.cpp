#include "Population.h"



Population::Population()
{
}

void Population::generateStartPopulation()
{
	for (int i = 0; i < MAXPOP; ++i)
	{
		Chromosome newChrom;
		newChrom.generateRandom();
		population.push_back(newChrom);
	}
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
	return bestChromByNow;
}

void Population::cross()
{
	std::vector<Chromosome> children;
	srand(time(0));

	for (int i = 0; i < MAXPOP-1; ++i)
	{
		Chromosome child;
		int crossPoint = std::rand() % CHROMLENGHT;
		int j = 0;
		while (j != crossPoint)
		{
			child.chrom.push_back(population[i].chrom[j]);
		}
	}
}



Population::~Population()
{
}
