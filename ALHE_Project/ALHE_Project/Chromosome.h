#pragma once
#include <vector>


//Konwencja: true: pierwsza kupka (A), false: druga kupka(B)
class Chromosome
{

public:
	int aValue = 35;
	std::vector<bool> chrom;
	Chromosome() {}
	Chromosome(int value);
	~Chromosome();
	void generateRandom();
	int calculateCost(int aValue) const;
	void print();
	void test();
	bool operator<(const Chromosome &c2);
};

