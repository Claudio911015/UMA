#include "Curve.h"

#include <cmath>
#include <stdexcept>
#include <iostream>

double Curve::discountFactorTo(double t) const{
//	if (m_data.empty() || m_data.back().m_time<t)
//		throw std::runtime_error ("not enough data");
	//Allow extrapolation
	if(m_data.empty())
		return 1;
	double lastTime = 0;
	double val = 1;
	
	for(size_t n=m_data.size(), i=0; i!=n; ++i)
	{
		const auto& p = m_data[i];
		if(p.m_time>=t || n-1==i){
			val *= exp((lastTime-t)*p.m_x);
			break;
		}
		val *= exp((lastTime-p.m_time)*p.m_x);
		lastTime=p.m_time;
	}
	return val;
}

void Curve::finalFixedDiscountFactor(double& time, double& x) const
{
	if(m_data.size()<2u){
		time=0;
		x=1;
		return;
	}
	time = m_data[m_data.size()-2u].m_time;
	x=discountFactorTo(time);
}

void Curve::setDiscountFactorToLaterPoint(double time, double x)
{
	TimePoint t(time);
	
	double lastTime, lastDF;
	if(m_data.empty())
	{
		lastTime = 0;
		lastDF = 1;
	}
	else
	{
		lastTime = m_data.back().m_time;
		lastDF = discountFactorTo(lastTime);
	}

	double dfOverLastPeriod = x/lastDF;
	double timeOverLastPeriod = time-lastTime;
	t.m_x = log(dfOverLastPeriod)/(-timeOverLastPeriod);
	m_data.push_back(t);
}

void Curve::dfWithLastPoint(double time, double lastrate, double& df, double& grad)
{
	size_t size = m_data.size();
	m_data[size-1].m_x = lastrate;
	df = discountFactorTo(time);
	double lastKnownTime = size>1 ? m_data[size-2].m_time : 0;
	if(time <= lastKnownTime){
		grad = 0;
		return;
	}
	//df is constant * exp((lastKnownTime-t)x)
	//grad is constant * (lastKnownTime-t) * exp((lastKnownTime-t)x) = (lastKnownTime-t) df
	grad = df * (lastKnownTime-time);
}

void Curve::appendPoint (double time)
{
	TimePoint t(time);
	t.m_x = 0;
	m_data.push_back(t);
}

void Curve::print() const{
	for (const TimePoint& p : m_data)
		std::cout<<p.m_time<<","<<p.m_x<<"\n";
}
