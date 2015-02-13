/*****************************  ContinuousTime.h  **********************************
* Author:        Brian W.
* Date created:  2015-02-08-12.55
* Last modified:
* Project:       BlackScholesModel
*
*
* Description:
* just an interface for the Models (Black-scholes) which use the time's continuity as an hypothesis
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

#ifndef CONTINUOUSTIME_H
#define CONTINUOUSTIME_H
#include "DiscountFactor.h"
#include "PricerModel.h"


class ContinuousTime : public PricerModel
{
    public:
        ContinuousTime();

        virtual ~ContinuousTime();
    protected:
    private:

};

#endif // CONTINUOUSTIME_H
