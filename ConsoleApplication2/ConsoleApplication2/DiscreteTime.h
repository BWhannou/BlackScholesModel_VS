/*****************************  ContinuousTime.h  **********************************
* Author:        Brian W.
* Date created:  2015-02-08-12.55
* Last modified:
* Project:       BlackScholesModel
*
*
* Description:
* just an interface for the Models (Binomial) which use a discrete time
*
* Member attributes:
* ===========================
*
*
*
* Member functions (methods):
* ===========================
*
* Further documentation:
* ======================
*
*******************************************************************************/
#ifndef DISCRETETIME_H
#define DISCRETETIME_H
#include "DiscountFactor.h"
#include "PricerModel.h"
#include "Option.h"

class DiscreteTime : public PricerModel
{
    public:
        DiscreteTime();
        ~DiscreteTime();

    protected:

    private:

};

#endif // DISCRETETIME_H
