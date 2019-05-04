#include "IRSwap.h"

#include "Curve.h"
#include <iostream>

void IRSwap::adjustCurveToPriceFairly(Curve& c) const
{
	double curveFixedTo = c.getFinalTime();
	int knownFixings = 0;
	double knownValue = 0;
	double lastTime = 0;
	for(double t : m_paymentTimes)
	{
		if(t<=curveFixedTo)
		{
			++knownFixings;
			knownValue += (t-lastTime) * m_rate * 0.01 * c.discountFactorTo(t);
			lastTime = t;
		}
	}
	int unknownFixings = m_paymentTimes.size()-knownFixings;
	//std::cout<<__LINE__<<std::endl;
	if(unknownFixings==1)
	{//the easy case
		//solve the equation 1-df(mat)=knownValue + df(mat)*m_rate*0.01*(mat-lastTime)
		//<=> df(mat) = (1-knownValue)/(1+m_rate*0.01*(mat-lastTime))
		double mat = m_paymentTimes.back();
		c.setDiscountFactorToLaterPoint(mat,(1-knownValue)/(1+m_rate*0.01*(mat-lastTime)));
		return;
	}
	
	//wanna solve 1-df(mat)=knownValue + sum_i df(t_i)*m_rate*0.01*(t_i-t_{i-1})
	//all the dfs are functions of x
	//let F(x)=knownValue + sum_i df(t_i)*m_rate*0.01*(t_i-t_{i-1}) + df(mat) -1
	//then F'(x) = df(mat)' + sum_i df(t_i)'*m_rate*0.01*(t_i-t_{i-1})
	c.appendPoint(m_paymentTimes.back());
	double x = 0;
	int iteration = 15;
	double firstStartTime = knownFixings==0 ? 0 : m_paymentTimes[knownFixings-1];
	while(--iteration>=0)
	{
		double F, dFdx;
		c.dfWithLastPoint(m_paymentTimes.back(),x,F,dFdx);
		F+= knownValue -1;
		double lastTime=firstStartTime;
		for(int i = knownFixings; i<m_paymentTimes.size();++i)
		{
			double df, ddfdx;
			c.dfWithLastPoint(m_paymentTimes[i],x,df,ddfdx);
			double timeDifference = m_paymentTimes[i]-lastTime;
			F+=m_rate*0.01*timeDifference*df;
			dFdx+=m_rate*0.01*timeDifference*ddfdx;
			lastTime = m_paymentTimes[i];
		}
		//std::cout<<x<<","<<F<<std::endl;
		x-=F/dFdx;
	}
}

