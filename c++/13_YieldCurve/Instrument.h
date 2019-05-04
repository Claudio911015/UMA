#ifndef INSTRUMENT_H
#define INSTRUMENT_H

class Curve;

class Instrument{
public:
	//virtual void getValue(const Curve& c) const=0;
	//virtual void getMarketPrice() =0;
	virtual double getExpiry() const=0;
	virtual void adjustCurveToPriceFairly(Curve& c) const =0;
	virtual ~Instrument(){}
};


#endif
