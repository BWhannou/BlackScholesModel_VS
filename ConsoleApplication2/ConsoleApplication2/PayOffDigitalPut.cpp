/**************************   PayOffDigitalPut.cpp   **********************************
* Author:        W. Brian
*
* Date created:  2015-02-12-18.14$
* Last modified: 2015-02-12
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
#include "PayOffDigitalPut.h"

PayOffDigitalPut::PayOffDigitalPut(double strike_,double FixedPayment_):
    Strike(strike_), FixedPayment(FixedPayment_)
{
    //ctor
}

PayOffDigitalPut::~PayOffDigitalPut()
{
    //dtor
}

double PayOffDigitalPut::operator() (double Spot)const
{
    if (Spot>=Strike)
    {
        return 0.0;
    }
    else
    {
        return FixedPayment;
    }
}


PayOffDigitalPut* PayOffDigitalPut::clone() const
{
    return new PayOffDigitalPut(*this);
}

PayOffDigitalPut::PayOffDigitalPut(const PayOffDigitalPut& other)
{
    //copy ctor
    Strike=other.Strike;
    FixedPayment=other.FixedPayment;
}

PayOffDigitalPut& PayOffDigitalPut::operator=(const PayOffDigitalPut& rhs)
{
    if (this != &rhs)
    {
        Strike=rhs.Strike;
        FixedPayment=rhs.FixedPayment;
    }
    return *this; // handle self assignment
    //assignment operator
}
