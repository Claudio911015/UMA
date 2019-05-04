#ifndef BOOTSTRAPPER_H
#define BOOTSTRAPPER_H

#include <memory>
#include <vector>
#include "Instrument.h"
#include "Curve.h"

class Bootstrapper
{
public:
	Bootstrapper(std::vector<std::unique_ptr<Instrument>>& source);//swaps from the input
	Curve go();
private:
	std::vector<std::unique_ptr<Instrument>> m_source;
};

#endif
