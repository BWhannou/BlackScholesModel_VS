/*****************************  DiscountFactor.h  **********************************
* Author:        Brian W.
* Date created:  2015-02-08-12.55
* Last modified:
* Project:       BlackScholesModel
*
*
* Description:
* it is an abstract Class. it's an interface.
*
* Member attributes:
* ===========================
* double Maturity:
*
*
* double Rate
*
*
* Member functions (methods):
* ===========================
* two constructors and the destructor.
*
* the getters and setters of the attributes.
*
* assignment operator.
*
* DF(): discount factor. Pure virtual method !!!
* Clone(): replicates the object and returns a pointer to it. Pure virtual method !!!
*
* Further documentation:
* ======================
*
*******************************************************************************/

#ifndef DISCOUNTFACTOR_H
#define DISCOUNTFACTOR_H


class DiscountFactor
{
    public:
        DiscountFactor(double,double);
        DiscountFactor();
        virtual ~DiscountFactor();

        virtual double GetMaturity() const { return Maturity; }
        virtual void SetMaturity(double val) { Maturity = val; }

        virtual double GetRate() const { return Rate; }
        virtual void SetRate(double val) { Rate = val; }

        virtual double DF() const=0; // pure virtual function, it does nothing
        virtual DiscountFactor* Clone() const=0;
    protected:
		double Maturity;
        double Rate;
    private:

};

#endif // DISCOUNTFACTOR_H
