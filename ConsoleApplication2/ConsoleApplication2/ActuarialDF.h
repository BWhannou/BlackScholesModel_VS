/*****************************  ActuarialDF.h  **********************************
* Author:        Brian W.
* Date created:  2015-02-08-12.55
* Last modified:
* Project:       BlackScholesModel
*
*
* Description:
* it is a discount factor which give the present value of one euro in "Maturity" years.
* the expression of this discount is : 1/(1+rate)^(Maturity).
* This class inherited from the abstract class DiscountFactor.
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
* DF(): discount factor
* Clone(): replicates the object and returns a pointer to it.
*
* Further documentation:
* ======================
*
*******************************************************************************/
#ifndef ACTUARIALDF_H
#define ACTUARIALDF_H

#include "DiscountFactor.h"


class ActuarialDF : public DiscountFactor
{
    public:
        ActuarialDF(double Maturity_,double Rate_);
        ActuarialDF(const ActuarialDF& other);
        virtual ~ActuarialDF();
        ActuarialDF& operator=(const ActuarialDF& other);


        virtual double GetMaturity() const { return Maturity; }
        virtual void SetMaturity(double val) { Maturity = val; }

        virtual double GetRate() const { return Rate; }
        virtual void SetRate(double val) { Rate = val; }

        virtual double DF() const;
        virtual ActuarialDF* Clone() const;
    protected:
    private:

};

#endif // ACTUARIALDF_H
