/*****************************  Binomial.h  **********************************
* Author:        Brian W.
* Date created:  2015-02-08-12.55
* Last modified:
* Project:       BlackScholesModel
*
*
* Description:
* it calculates the price with the binomial model. this class inherited from the abstract class DiscreteTime
*
* Member attributes:
* ===========================
* double down: when the underlying value goes "down", the value will fall from S to down*S
*
* double up: when the underlying value goes "up", the value will go from S to up*S
*
* double firstSpot: the underlying value at the beginning
*
* DiscountFactor* MyDFPtr: it's a pointer to a discount factor. it'll be used to get the maturity of the option and
* to discount the expectation value of the option
*
*
* Member functions (methods):
* ===========================
* the constructor(double up_,double down_,double firstSpot_,const DiscountFactor& theDF_): it creates the pointer MyDFPtr
* indirectly using "new" method through the method DiscountFactor* DiscountFactor::Clone(const DiscountFactor&)
*
* the destructor: it deletes MyDFPtr
*
* the getters and setters of the attributes (expect MyDFPtr).
*
* double RiskNeutralProb() const: gives the risk neutral Probability
*
* std::queue<double> Graph(): it gives a way to calculate the underlying value at any period before the maturity of the option
*
* std::queue<double> OptionGraph(): using Graph() so using the underlying value to calculate the option payoff at the maturity.
* at every outcomes of the underlying values
*
* virtual double Price(const Option&)
*
* Further documentation:
* ======================
*
*******************************************************************************/
#ifndef BINOMIAL_H
#define BINOMIAL_H

#include "DiscreteTime.h"


#include <math.h>
#include <queue>
#include "Option.h"
#include "DiscountFactor.h"
#include "PayOff.h"

class Binomial : public DiscreteTime
{
    public:
        Binomial(double up_,double down_,double firstSpot_,const DiscountFactor& theDF_);
//        Binomial(double up_,double down_,double firstSpot_,DiscountFactor* theDFPtr_);
        virtual ~Binomial();

        double Getup() { return up; }
        void Setup(double val) { up = val; }

        double Getdown() { return down; }
        void Setdown(double val) { down = val; }

        double GetfirstSpot() { return firstSpot; }
        void SetfirstSpot(double val) { firstSpot = val; }

        Binomial& operator=(const Binomial& rhs);

        double RiskNeutralProb() const;
        std::queue<double> Graph() const;
		std::queue<double> OptionGraph(const Option&);
        virtual double Price(const Option&) ;
    protected:
    private:
        double down;
        double up;
        double firstSpot;
        DiscountFactor* MyDFPtr;
};

#endif // BINOMIAL_H



