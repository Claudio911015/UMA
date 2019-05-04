#ifndef MARKETDATA_H
#define MARKETDATA_H

class MarketData
{
public:
	
	//deterministic discount factors - can be used for forwarding the equity and discounting.
   virtual double discountFactorTo(double time)const=0;
   virtual double equityPrice() const = 0;
   virtual double equityVolatility() const = 0; //this is not a percentage
};

#endif
