/*****************************  BlackS.h  **********************************
* Author:        Brian W.
* Date created:  2015-02-08-12.55
* Last modified:
* Project:       BlackScholesModel
*
*
* Description:
* it calculates the price with the Black-Scholes model. this class inherited from the abstract class ContinuousTime
*
* Member attributes:
* ===========================
* double volatility:
*
* double firstSpot: the underlying value at the beginning
*
* DiscountFactor* MyDFPtr: it's a pointer to a discount factor. it'll be used to get the maturity of the option and
* to discount the expectation value of the option
*
* double StdE:
*
* Member functions (methods):
* ===========================
* the constructor(double Volatility_,double FirstSpot_,DiscountFactor& theDF): it creates the pointer MyDFPtr
* indirectly using "new" method through the method DiscountFactor* DiscountFactor::Clone(const DiscountFactor&)
*
* the destructor: it deletes MyDFPtr
*
* the getters and setters of the attributes (expect MyDFPtr).
*
* BlackS& operator= (const BlackS& rhs): assignment operator
*
* double GetOneStockValue(UniGen& )const: it gives the value of the stock at the maturity using the black-Scholes formula
*
* double GetPayOffValue(Option&, UniGen&): just apply the result of the previous function to the payoff of the option
*
* virtual double Price(const Option): not-used function. it was needed to overload the pure virtual function of the mother class
*
* double PriceMersenne(const Option&,int,int)
* double PriceMersenne(const Option&,double,int) gives the price of an option using the mersenne twister as a uniform random generator.
* this function is overloaded in order to used two type of stop criteria: one based on the number of loops, the other based on
* standard error estimator
*
*
* Further documentation:
* ======================
* BlackScholesModel_BW.pdf
*******************************************************************************/
#ifndef BLACKS_H
#define BLACKS_H
#include "DiscountFactor.h"
#include "ContinuousTime.h"
#include "UniGen.h"
#include "Option.h"

class BlackS : public ContinuousTime
{
    public:
        BlackS(double Volatility_,double FirstSpot_,DiscountFactor& theDF);
//        BlackS(double Volatility_,double FirstSpot_,DiscountFactor* theDFPtr_);
        virtual ~BlackS();

        double GetVolatility() { return Volatility; }
        void SetVolatility(double val) { Volatility = val; }

        double GetFirstSpot() { return FirstSpot; }
        void SetFirstSpot(double val) { FirstSpot = val; }
        BlackS& operator= (const BlackS& rhs);


        double GetStdE() { return StdE; }
        void SetStdE(double val) { StdE = val; }

		int GetLoop() {return Loop;}

        double GetOneStockValue(UniGen& theUniGen_)const;
        double GetPayOffValue(Option& theOption_,UniGen& theUniGen_)const;
        virtual double Price(const Option&) {return 0.0;};
        double PriceMersenne(Option& theOption_,int stopCriteria_,int seed_);
        double PriceMersenne(Option& theOption_,double stopCriteria_,int seed_);
    protected:
    private:
        double Volatility;
        double FirstSpot;
        DiscountFactor* MyDFPtr;
        double StdE;
		int Loop;
};

#endif // BLACKS_H
