#include "UniGenLC.h"
#include <cmath>

UniGenLC::UniGenLC(double Seed_): Seed(Seed_)
{
    Current=Seed_;
    //ctor
}

UniGenLC::~UniGenLC()
{
    //dtor
}

double UniGenLC::Random()
{
    const int a=1103515245;
    const int c(12345);
    const int m(pow(2,3));
    int x=floor(Current*(pow(2,31)-1));
    x=(a*x+c)%m;
    Current=(double)x/(pow(2,31)-1);

    return Current;
}
