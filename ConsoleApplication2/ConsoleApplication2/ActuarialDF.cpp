#include "ActuarialDF.h"
#include <math.h>

ActuarialDF::ActuarialDF(double Maturity_,double Rate_):
    DiscountFactor(Maturity_,Rate_)
{
    //ctor
}

ActuarialDF::~ActuarialDF()
{
    //dtor
}

 double ActuarialDF::DF() const
{
    double a=pow(1+Rate,Maturity);
    return pow(a,-1);
}


ActuarialDF::ActuarialDF(const ActuarialDF& other):
    DiscountFactor(other.Maturity,other.Rate)
{
    //copy ctor

}

ActuarialDF& ActuarialDF::operator=(const ActuarialDF& rhs)
{
    if (this != &rhs)
    {
    Maturity=rhs.Maturity;
    Rate=rhs.Rate;
    }
    return *this; // handle self assignment
    //assignment operator
}
ActuarialDF* ActuarialDF::Clone() const
{
    return new ActuarialDF(*this);
}
