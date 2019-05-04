#ifndef PAYOFF_H
#define PAYOFF_H

class Payoff{
public:
  virtual double timeToExpiry() const = 0;
  virtual double payoffOnExpiry(double equityPrice) const = 0;
};

#endif
