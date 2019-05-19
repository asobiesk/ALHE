#include "Chromosome.h"
#include<cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

//Konwencja: true: pierwsza kupka (A), false: druga kupka(B)


Chromosome::Chromosome(int value)
{		
	aValue = value;
}

Chromosome::~Chromosome()
{
}

void Chromosome::init() 
{
	for(int i = 0; i < 10; ++i)
		chrom.push_back(false);
}

void Chromosome::set(int a) 
{
	size_t i = 0;
	while (a > 0)
	{
		chrom[i] = a % 2 == 0;
		++i;
		a /= 2;
	}
}

void Chromosome::generateRandom()
{

	for (int i = 0; i < 10; ++i)
	{
		int rand = std::rand() % 2;
		bool randBool = (rand == 0);
		chrom.push_back(randBool);
	}
}

int Chromosome::calculateCost(int aValue) const
{
	int aSum = 0;

	for (int i = 0; i < 10; ++i)
	{
		if (chrom[i])
			aSum += (i + 1);		
	}
	return (std::abs(aValue - aSum));
}

void Chromosome::test()
{
	generateRandom();
	print();
	std::cout << "Cost: " << calculateCost(aValue) << std::endl;
}

bool Chromosome::operator<(const Chromosome & c2)
{
	return (calculateCost(aValue) < c2.calculateCost(aValue));
}

void Chromosome::print()
{
	for (bool i : chrom)
		std::cout << i << " ";
	std::cout << std::endl;
}
