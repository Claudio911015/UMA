#ifndef EUROPEAN_OPTION_H
#define EUROPEAN_OPTION_H

#include "Payoff.h"
class Results;
class MarketData;

class EuropeanOption : public Payoff {
public:
	EuropeanOption(bool put, double strike, double maturity)
		: m_isPut(put), m_maturity(maturity), m_strike(strike) {}
	
	Results analyticPrice(const MarketData& m) const;
	
	double timeToExpiry() const override;
	
	double payoffOnExpiry(double equityPrice) const override;
	
private:
	bool m_isPut;
	double m_maturity, m_strike;
};

#endif
