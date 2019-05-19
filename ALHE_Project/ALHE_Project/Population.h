#pragma once
#include"Chromosome.h"
#include <vector>

#define MAXPOP 10
#define CHROMLENGHT 10

class Population
{
private:
	std::vector<Chromosome> population;
	Chromosome best;

public:
	Population();
	~Population();
	void generateStartPopulation();
	void cross();
	void mutate();
	Chromosome chooseBest();

};

