#pragma once
#include"Chromosome.h"
#include <vector>
#include <ctime>
#include <cmath>

#define MAXPOP 10
#define CHROMLENGHT 10

class Population
{
private:
	std::vector<Chromosome> population;
	Chromosome best;
	int aValue = 35;

public:
	Population() {}
	Population(int value);
	~Population();
	void generateStartPopulation();
	void cross();
	void mutate();
	bool stopCond();
	void print();
	void shufflePopulation();
	Chromosome getBest() { return best; }
	Chromosome chooseBest();

};

