#include <cmath> //for log, sqrt and erf
#include <iostream>

#include "EuropeanOption.h"
#include "MarketData.h"
#include "Payoff.h"
#include "Pricer.h"

class SimpleMarketData : public MarketData{
   double discountFactorTo(double time) const override { 
   		double rate = 0.03;
   		return exp(-rate*time);
   }
   double equityPrice() const override {return 100;}
   double equityVolatility() const override {return 0.2;}
};

void printResults(const Results& r){
	std::cout<<"Price: "<<r.m_price<<", SD: "<<r.m_standardDeviation
		<<", Delta: "<<r.m_delta<<", Gamma: "<<r.m_gamma<<"\n";
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	SimpleMarketData m;
	EuropeanOption call(false, 102.,0.2);
	EuropeanOption put(true, 102,0.2);
	Pricer p(10000);

	std::cout<<"Call:\n";
	std::cout<<"Analytic:\n";
	printResults(call.analyticPrice(m));
	std::cout<<"Monte Carlo:\n";
	printResults(p.go(m,call));

	std::cout<<"\nPut:\n";
	std::cout<<"Analytic:\n";
	printResults(put.analyticPrice(m));
	std::cout<<"Monte Carlo:\n";
	printResults(p.go(m,put));
	
	return 0;
}
