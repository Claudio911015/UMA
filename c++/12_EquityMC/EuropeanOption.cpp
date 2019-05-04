#include "EuropeanOption.h"
#include "BasicMaths.h"
#include "MarketData.h"
#include "Pricer.h"

#include <cmath>
#include <iostream>

Results EuropeanOption::analyticPrice(const MarketData& m) const
{
	Results out;
	out.m_standardDeviation = 0;
	double df = m.discountFactorTo(m_maturity);
	double fwd = m.equityPrice()/df;
	double d1 = (std::log(fwd/m_strike)+m_maturity*m.equityVolatility()*m.equityVolatility()*0.5)
					/(m.equityVolatility()*std::sqrt(m_maturity));
	double d2 = d1-m.equityVolatility()*std::sqrt(m_maturity);
	
	//std::cout<<"Ns "<<Ncdf(d1)<<","<<Ncdf(d2)<<","<<df<<std::endl;
	
	//std::cout<<"delta "<<Ncdf(d1)<<"\n";
	//std::cout<<"gamma "<<Npdf(d1)/(m.equityVolatility()*sqrt(m_maturity)*m.equityPrice())<<"\n";
	//std::cout<<"vega "<<Npdf(d1)*sqrt(m_maturity)*m.equityPrice()<<"\n";
	
	if(!m_isPut)
	{
		out.m_price = m.equityPrice()*Ncdf(d1)-m_strike*Ncdf(d2)*df;
	}
	else
	{
		out.m_price = m_strike*Ncdf(-d2)*df-m.equityPrice()*Ncdf(-d1);
	}
	out.m_delta = Ncdf(d1) - (m_isPut ? 1.0 : 0.0);
	out.m_gamma = Npdf(d1)/(m.equityPrice()*m.equityVolatility()*std::sqrt(m_maturity));
	return out;
}

double EuropeanOption::timeToExpiry() const {return m_maturity;}

double EuropeanOption::payoffOnExpiry(double equityPrice) const {
	double difference = equityPrice-m_strike;
	if(m_isPut)
		difference =- difference;
	if(difference>0)
		return difference;
	return 0;
}

