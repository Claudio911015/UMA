#include "IBOR.h"
#include "Curve.h"

void IBOR::adjustCurveToPriceFairly(Curve& c) const
{
	double marketDF = 1.0/(1.0+m_rate*m_expiry/100);
	c.setDiscountFactorToLaterPoint(m_expiry,marketDF);
}
