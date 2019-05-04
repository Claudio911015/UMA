#include <cmath>
#include <iostream>
#include <vector>
#include "Pricer.h"

namespace{
//this function could be a member function of Pricer, but I'm trying not to modify the headers
Results calculate(const MarketData& m, const Payoff& p, int paths, std::mt19937& rnd, double spot)
{
	double s=std::sqrt(p.timeToExpiry())*m.equityVolatility();
	std::lognormal_distribution<double> dist(-0.5*s*s,s);
	Results r{};
	std::vector<double> iid;
	iid.reserve(paths);
	double finalDF = m.discountFactorTo(p.timeToExpiry());
	for(int i=0; i!=paths; ++i)
	{
		double finalspot = spot * dist(rnd)/finalDF;
		iid.push_back(finalDF*p.payoffOnExpiry(finalspot));
	}
	
	double sum = 0, sumsq = 0;
	for(double d : iid)
	{
		sum += d;
		sumsq += d*d;
	}
	
	r.m_price = sum / paths;
	r.m_standardDeviation=sqrt(sumsq/paths-r.m_price*r.m_price)/sqrt(paths);
	if(!std::isfinite(r.m_standardDeviation))
		r.m_standardDeviation=0;
	
	return r;
}
}//end of anonymous namespace

Results Pricer::go(const MarketData& m, const Payoff& p)
{
	//copy the initial state of the rnd for the bumped calculation so that greeks are unaffected by sampling error
	std::mt19937 copyrnd = m_rnd;
	std::mt19937 copyrnd2 = m_rnd;
	
	Results r = calculate(m,p,m_numIndependentPaths,m_rnd, m.equityPrice());
	double bumpRatio = 0.01;
	double bumpSize = m.equityPrice()*bumpRatio;
	Results up = calculate(m,p,m_numIndependentPaths,copyrnd, m.equityPrice()+bumpSize);
	Results down = calculate(m,p,m_numIndependentPaths,copyrnd2, m.equityPrice()-bumpSize);
	r.m_delta = (up.m_price-down.m_price)/(2*bumpSize);
	r.m_gamma = (up.m_price+down.m_price-2*r.m_price)/(bumpSize*bumpSize);
	return r;
}


