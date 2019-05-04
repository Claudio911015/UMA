#ifndef IRFUTURE_H
#define IRFUTURE_H

#include "Instrument.h"

//All times are in fractions of a year.
//An IRFuture of rate 96.7 with an expiry of 0.4 and a tenor of 0.25 means that 
//the market expects that at time 0.4 the 3M IBOR will be (100-96.7)/100, i.e. 3.3%.
//In other words, (discount factor to 0.4+0.25)/(discount factor to 0.4) = 1/(1+3.3*0.25) = 100/(100+(100-96.7)*0.25)
//All rates are assumed to be deterministic and risk free in this project

class IRFuture : public Instrument {
public:
	IRFuture(double expiry, double tenor, double rate)
	   :m_expiry(expiry), m_tenor (tenor), m_rate(rate){}
	double getExpiry() const override {return m_expiry+m_tenor;}
	
	//If the yield curve is not already fixed as far as expiry, this should fix the current value of 
	//the discount factor to expiry.
	void adjustCurveToPriceFairly(Curve& c) const override;
private:
	double m_expiry, m_tenor, m_rate;
};

#endif
