/**************************      **********************************
* Author:        W. Brian
*
* Date created:  2015-02-12-18.24$
* Last modified:
* Project:       BlackScholesModel$
* Platform:      Any C++
* Description:
*
*
*
* Further documentation:
*
*
*******************************************************************************/
#include "PayOffDigitalCall.h"

PayOffDigitalCall::PayOffDigitalCall(double Strike_, double FixedPayment_):
    Strike(Strike_), FixedPayment(FixedPayment_)
{
    //ctor
}

PayOffDigitalCall::~PayOffDigitalCall()
{
    //dtor
}

double PayOffDigitalCall::operator() (double spot) const
{
    if (spot<=Strike)
    {
        return 0.0;
    }
    else
    {
        return FixedPayment;
    }
}


PayOffDigitalCall* PayOffDigitalCall::clone() const
{
    return new PayOffDigitalCall(*this);
}


PayOffDigitalCall::PayOffDigitalCall(const PayOffDigitalCall& other)
{
    //copy ctor
    Strike=other.Strike;
    FixedPayment=other.FixedPayment;
}

PayOffDigitalCall& PayOffDigitalCall::operator=(const PayOffDigitalCall& rhs)
{
    if (this != &rhs)
    {
        Strike=rhs.Strike;
        FixedPayment=rhs.FixedPayment;
    }
    return *this; // handle self assignment
    //assignment operator
}
