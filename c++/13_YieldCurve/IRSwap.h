#ifndef IRSWAP_H
#define IRSWAP_H

#include "Instrument.h"
#include <vector>

//An interest rate swap is made of a fixed leg and a float leg
//WLOG we assume the notional is 1
//At each payment date, the fixed leg pays rate% * [time since previous payment time]
//(where [time since previous payment time] is just the time since 0 for the first payment time.)
//The floating leg is approximated as having value one minus the discount factor to the last payment time.
//We are only interested in interest rate swaps which begin at time 0

class IRSwap : public Instrument {
public:
	IRSwap(const std::vector<double>& paymentTimes, double rate) //rate is a percentage
	   :m_paymentTimes(paymentTimes), m_rate(rate){}
	double getExpiry() const override {return m_paymentTimes.back();}
	
	//If the yield curve is not already fixed as far as expiry, this should fix the current value of 
	//the discount factor to expiry.
	void adjustCurveToPriceFairly(Curve& c) const override;
private:
	double m_rate;
	std::vector<double> m_paymentTimes;
};

#endif
