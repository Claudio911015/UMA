#ifndef IBOR_H
#define IBOR_H

#include "Instrument.h"

class IBOR : public Instrument {
public:
	IBOR(double expiry, double rate) //rate is a percentage
	   :m_expiry(expiry), m_rate(rate){}
	double getExpiry() const override {return m_expiry;}
	void adjustCurveToPriceFairly(Curve& c) const override;
private:
	double m_expiry, m_rate;
};

#endif
