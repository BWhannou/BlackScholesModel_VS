#include "Option.h"

Option::Option(PayOff& MyPayOff_,double Maturity_):Maturity(Maturity_)
{
    MyPayOffPtr= MyPayOff_.clone();
    //ctor
}

Option::~Option()
{
    delete MyPayOffPtr; /*destruction of MyPayOffPtr created by new in clone()*/
    //dtor
}

Option::Option(const Option& other)
{
    //copy ctor
}

Option& Option::operator=(const Option& rhs)
{
    if (this != &rhs)
    {
        Maturity=rhs.Maturity;
        delete MyPayOffPtr;
        MyPayOffPtr=rhs.MyPayOffPtr->clone();
    } // handle self assignment
    //assignment operator
    return *this;
}

double Option::OptionPayOff(double Spot) const
{
    return (*MyPayOffPtr)(Spot);
}
