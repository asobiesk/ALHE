#pragma once

int potega(int podstawa, int wykladnik)
{
	int wynik = podstawa;
	for (int i = 1; i < wykladnik; ++i)
		wynik *= podstawa;
	return wynik;
}

Chromosome bruteforce(int aValue)
{
	Chromosome najlepszy;
	Chromosome szukany;
	najlepszy.init();
	szukany.init();
	for (int i = 0; i < potega(2, szukany.chrom.size()); ++i)
	{
		szukany.set(i);
		if (najlepszy.calculateCost(aValue) > szukany.calculateCost(aValue))
			najlepszy = szukany;
		if (najlepszy.calculateCost(aValue) == 0)
			break;
	}

	return najlepszy;
}

Chromosome optimalAlgorithm(int aValue) 
{
	Chromosome wynik;
	wynik.init();
	int curValue = wynik.chrom.size() ;
	while (aValue != 0) 
	{
		if(aValue <= curValue)
		{
			wynik.chrom[aValue - 1] = true;
			aValue = 0;
		}
		else
		{
			wynik.chrom[curValue - 1] = true;
			aValue -= curValue;
			--curValue;
		}
	}
	return wynik;
}