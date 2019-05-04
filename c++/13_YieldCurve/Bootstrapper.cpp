#include "Bootstrapper.h"

#include <algorithm>
#include <stdexcept>

bool lessThanInsts(const std::unique_ptr<Instrument>& a, const std::unique_ptr<Instrument>& b){
		return a->getExpiry()<b->getExpiry();
}

Bootstrapper::Bootstrapper(std::vector<std::unique_ptr<Instrument>>& source)
{
	source.swap(m_source);
	std::sort(m_source.begin(), m_source.end(), lessThanInsts);
	for(size_t i=1; i<m_source.size();++i)
	{
		if(!lessThanInsts(m_source[i-1],m_source[i]))
			throw std::runtime_error("duplicate time in input data");
	}
	
}

Curve Bootstrapper::go()
{
	Curve c;
	for(const auto& i : m_source)
		i->adjustCurveToPriceFairly(c);
	return c;
}
