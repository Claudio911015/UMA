Yield curve bootstrapping.

There are 3 common market-traded financial instruments whose price is very sensitive to interest rates and not very 
sensitive to the volatiltity of interest rates. It is traditional to build a yield curve of future interest rates 
based on their market prices.

They are
1) Cash/deposits/IBORs - the interest rate of a loan today.
 a cash rate of x at t means that 1 invested today is worth 1+xt at time t. (in particular x is a percentage)
2) futures and forwards on interest rates
 These are quoted in the usual convention where a rate of 100-x for a tenor of t expiring at s means that
 the market expects the cash rate at s to be x for t.
3) interest rate swaps.
 A rate of r means that a fixed leg paying r% * (distance from previous date) at each of the given dates is worth the same as
 the interest payment on a loan of 1 repaid at the last date. This is a "vanilla floating leg" approximation.

This project builds the curve of discount factors t->discountFactor(t) from time 0=now based on these instruments.
It makes a few simplifying assumptions which have varying importance but which would not always be made in the real world:

-all times are given in exact fractions of years, there is no consideration of dates, 
	daycount conventions, futures codes, rollover etc.
-we neglect the possibility that data may clash or need to be prioritised.
-there are no settlement delays (e.g. a loan taken out today might not actually arrive until 2 working days time)
-IBORs are assumed quoted in simple compounding.
-liquidity/credit/basis risk is ignored (this was quite a common approximation before 2007)
-swaps are assumed to refer to the same curve as they discount on.

The code:
We assume the Bootstrapper is provided with a vector of all the market instruments,.

The Curve object represents the curve as known so far. 
It doesn't care if rates are negative.
As currently implemented, it stores continuously compounded forward rates. Other possibilities - e.g. log discount factors - would also work,
and the interface would not need to be changed.
It can be modified in two ways  - adding an extra known discount factor is the simplest.
Alternatively, you can just add a point with an arbitrary rate, then set that rate with "dfWithLastPoint", 
which gives you the value and derivative of a discount factor which depends on that rate. This is needed to implement a Newton search.

The three instrument types (IBOR, IRFuture, IRSwap) implement the Instrument interface, which means that they all add their data to the curve in a 
consistent way.


