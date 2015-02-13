#include "PayOffPut.h"

PayOffPut::PayOffPut(double Strike_):Strike(Strike_)
{
    //ctor
}

PayOffPut::~PayOffPut()
{

    //dtor
}

PayOffPut::PayOffPut(const PayOffPut& other)
{
    Strike=other.Strike;
    //copy ctor
}

PayOffPut& PayOffPut::operator=(const PayOffPut& rhs)
{
    if (this != &rhs)
    {
        Strike=rhs.Strike;
    } // handle self assignment
    //assignment operator
    return *this;
}

double PayOffPut::operator() (double Spot) const
{
    if (Spot > Strike)
        return 0;
    else
        return Strike - Spot;
}

PayOffPut* PayOffPut::clone() const
{
    return new PayOffPut(*this);
}
