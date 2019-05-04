#ifndef CURVE_H
#define CURVE_H

#include<vector>

class TimePoint{
public:
	TimePoint(double time):m_time(time), m_x(0){}
	double m_time, m_x;	
};

//represents piecewise linearly interpolated forward rates
class Curve{
public:
	Curve(){}
	
	double discountFactorTo(double t) const;
	void finalFixedDiscountFactor(double& time, double& x) const;
	double getFinalTime() const {return m_data.empty() ? 0 : m_data.back().m_time;}
	//void modifyLastPoint(double x){m_data.back().m_x = x;}
	void print() const;

	void setDiscountFactorToLaterPoint(double time, double x);
	
	void appendPoint (double time); //add a discount factor to the curve with an arbitrary rate
	void dfWithLastPoint(double time, double lastrate, double& df, double& grad); //grad outputs d df / d lastrate
	
private:
	std::vector<TimePoint> m_data;
};

#endif
