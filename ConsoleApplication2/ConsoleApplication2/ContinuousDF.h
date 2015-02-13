/*****************************  ContinuousDF.h  **********************************
* Author:        Brian W.
* Date created:  2015-02-08-12.55
* Last modified:
* Project:       BlackScholesModel
*
*
* Description:
* it is a discount factor which give the present value of one euro in "Maturity" years.
* the expression of this discount is : exp (-r*T).
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
#ifndef CONTINUOUSDF_H
#define CONTINUOUSDF_H

#include "DiscountFactor.h"

class ContinuousDF : public DiscountFactor
{
    public:
        ContinuousDF(double Maturity_,double rate_);
        ContinuousDF(const ContinuousDF& other);
        virtual ~ContinuousDF();

        virtual double GetMaturity() const { return Maturity; }
        virtual void SetMaturity(double val) { Maturity = val; }

        virtual double GetRate() const { return Rate; }
        virtual void SetRate(double val) { Rate = val; }


        ContinuousDF& operator=(const ContinuousDF& other);
        virtual double DF() const;
        virtual DiscountFactor* Clone() const;
    protected:
    private:

};

#endif // CONTINUOUSDF_H
