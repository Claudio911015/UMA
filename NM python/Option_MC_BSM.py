# -*- coding: utf-8 -*-
"""
Created on Sat May  4 12:20:12 2019

@author: claud
"""

import numpy as np
from matplotlib import pyplot as plt
from scipy import stats

class option():
    def __init__(self,CP,T,sigma,K,r):
            self.sigma=sigma
            self.T=T
            self.CP=CP
            self.K =float(K)
            self.r=r
            
    def BSM_value(self,S0):
        d1=(np.log(S0/self.K)+(self.r+0.5*self.sigma**2)*self.T)/(self.sigma*np.sqrt(self.T))
        d2=d1-self.sigma*np.sqrt(self.T)
        return(self.CP*S0*stats.norm.cdf(self.CP*d1,0.0,1.0)-self.CP*self.K*np.exp(-self.r*self.T)*stats.norm.cdf(self.CP*d2,0.0,1.0))
    
    def MC_value(self, S0,N):
        W=np.random.normal(0.0,1.0,N)
        Payoff=np.maximum(self.CP*S0*np.exp(W*np.sqrt(self.T)*self.sigma+(self.r-0.5*self.sigma**2)*self.T)-self.CP*self.K,0)
        return(np.mean(Payoff)*np.exp(-self.r*self.T))
        


c=option(1,1,0.1,1,0.05)
S=np.arange(0.00001,2,0.1)
c_prices_bs=[c.BSM_value(s) for s in S]
c_prices_mc=[c.MC_value(s,100) for s in S]
plt.figure()
plt.plot(S,c_prices_bs)
plt.plot(S,c_prices_mc)
