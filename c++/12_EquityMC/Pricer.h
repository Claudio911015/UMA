#ifndef PRICER_H
#define PRICER_H

#include <random>

#include "MarketData.h"
#include "Payoff.h"

class Results{
public:
	double m_price;	
	double m_standardDeviation; //the standard error of m_price
	double m_delta;
	double m_gamma;	
};

class Pricer{
public:
	Pricer(int nPaths):m_numIndependentPaths(nPaths){}
	
	Results go(const MarketData& m, const Payoff& p);
private:
	int m_numIndependentPaths;
	std::mt19937 m_rnd;
};

//perhaps add antithetic MC, more greeks, LR greeks, path dependent payoff.

#endif
