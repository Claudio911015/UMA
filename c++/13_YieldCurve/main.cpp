#include <iostream>
#include <memory>


#include "Curve.h"
#include "IBOR.h"
#include "IRFuture.h"
#include "Bootstrapper.h"
#include "IRSwap.h"

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(
                new T(std::forward<Args>(args)...));
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	std::vector<std::unique_ptr<Instrument>> insts;
	insts.push_back(make_unique<IBOR>(0.3, 8));
	insts.push_back(make_unique<IBOR>(0.6,6));
	insts.push_back(make_unique<IBOR>(0.9, 5));
	insts.push_back(make_unique<IRFuture>(0.91, 0.25, 95));

	insts.push_back(make_unique<IRSwap>(
		std::vector<double>({0.5,1.0,10.0, 15.0}),40)); 
 
	Bootstrapper b(insts);
	Curve c = b.go();
	std::cout<<"\n";
	c.print();
	
	return 0;
}
