Pricer.cpp is a pricer for an arbitrary derivative of one equity with a european payoff.
The equity is assumed to follow the Black-Scholes model with no repo rate or dividends.
It takes a generic market data object and a generic payoff.

EuropeanOption represents put or call option payoff and can also value the payoff theoretically using the 
Black-Scholes formula.

Tester counts how often a pricer is within its own reported standard deviation of a given true value.

In main, this program constructs a call option and checks with Tester the two methods of valuing it.

Simple enhancement task ideas
-allow a term structure of volatility
-allow a repo or dividend yield
-add deterministic dividends (split the equity into a Black-Scholes component and a dividend fund component)
-report vega, rho
-add path-dependent payoffs
-use antithetic sampling
-introduce the forward of the equity as a control variate.
-calculate greeks using the likelihood ratio method.

The Monte-Carlo pricer could be extended to more general models and payoffs beyond what an explicit formula can match.
