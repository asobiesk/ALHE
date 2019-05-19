#pragma once
#include <vector>

//Konwencja: true: pierwsza kupka (A), false: druga kupka(B)
class Chromosome
{

public:
	std::vector<bool> chrom;
	Chromosome();
	~Chromosome();
	void generateRandom();
	int calculateCost(int aValue);
	void print();
	void test();
};

