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
	Chromosome bestChromByNow;
	int bestCostByNow;


	

}



Population::~Population()
{
}
