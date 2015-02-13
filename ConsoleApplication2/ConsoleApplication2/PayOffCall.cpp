#include "PayOffCall.h"


PayOffCall::PayOffCall(double Strike_): Strike(Strike_)
{
    //ctor
}

PayOffCall::~PayOffCall()
{
    //dtor
}

PayOffCall::PayOffCall(const PayOffCall& other)
{
    //copy ctor
    Strike=other.Strike;
}

PayOffCall& PayOffCall::operator=(const PayOffCall& rhs)
{
    if (this != &rhs)
    {
        Strike=rhs.Strike;
    }
    return *this; // handle self assignment
    //assignment operator
}
double PayOffCall::operator () (double Spot) const
{
    if (Spot < Strike)
        return 0;
    else
        return Spot - Strike;
}

PayOffCall* PayOffCall::clone() const
{
    return new PayOffCall(*this);
}
