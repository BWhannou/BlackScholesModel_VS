#include "ContinuousDF.h"
#include <cmath>

ContinuousDF::ContinuousDF(double Maturity_,double Rate_):
	DiscountFactor(Maturity_,Rate_)
{
    //ctor
}

ContinuousDF::~ContinuousDF()
{
    //dtor
}

 double ContinuousDF::DF() const
{
    double a=Rate*Maturity;
    double res(exp(-a));

    return (res);
}


ContinuousDF::ContinuousDF(const ContinuousDF& other):
    DiscountFactor(other.Maturity,other.Rate)
{
    //copy ctor
}

ContinuousDF& ContinuousDF::operator=(const ContinuousDF& rhs)
{
    if (this != &rhs)
    {
    Maturity=rhs.Maturity;
    Rate=rhs.Rate;
    }
    return *this; // handle self assignment
    //assignment operator
}
DiscountFactor* ContinuousDF::Clone() const
{
    return new ContinuousDF(*this);
}

