# BlackScholesModel_VS

We're implementing an options Pricer which can use either a Binomial Model or a BlackScholes Model for the underlying. 

# Binomial model
for the Binomial model, we use the risk Neutral probability method and the std::queue object help us to iterate the calcul for any period.

# BlackScholes Model
For the BlackScholes Model, we use a mersenne twister Generator and Box-Muller algorithm to generate a normal distribution.
With this we're able to price:
-> Put 
-> Call
-> DigitalCall
-> DigitalPut

# work still ahead

-> exotic options
-> implied Volatility
