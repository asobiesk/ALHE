#pragma once
#include "Population.h"
#define STEPSLIMIT 2000
class Evolution
{
private: 
	Population population;
	int aValue;
public:
	Evolution(int value);
	~Evolution();
	Chromosome startAlgorithm();
	void startAlgorithmDebug();
};

