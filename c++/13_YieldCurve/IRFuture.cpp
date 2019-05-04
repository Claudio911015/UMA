#include "IRFuture.h"
#include "Curve.h"
#include <iostream>

void IRFuture::adjustCurveToPriceFairly(Curve& c) const
{
	double dfToExpiry = c.discountFactorTo(m_expiry);
	if(c.getFinalTime()<m_expiry)
	{
		c.setDiscountFactorToLaterPoint(m_expiry, dfToExpiry);
	}
	double maturityTime = m_expiry + m_tenor;
	double dfOverTerm = 100/(100 + m_tenor * (100-m_rate));
	c.setDiscountFactorToLaterPoint(maturityTime,dfOverTerm*dfToExpiry);
}
