

#include "BoxMuller.h"
#include <cmath>
#include "randomc.h"
BoxMuller::BoxMuller(double Mean_,double Sigma_):
	NormGen(Mean_,Sigma_)
{
    //ctor
}

BoxMuller::~BoxMuller()
{
    //dtor
}

double BoxMuller::Random(UniGen& theUniGen)
{
    double rand;
    double U,V;

    double raySquared;

    do
    {
        U=(theUniGen.Random()+1)/2;
        V=(theUniGen.Random()+1)/2;
        raySquared=U*U+V*V;
    }
    while
    (raySquared >=1.0);
    rand=U*sqrt(-2*log(raySquared)/raySquared);

    rand=Mean+Sigma*rand;

    return rand;
}

CRandomMersenne randM(1000);
double BoxMuller::Random()
{
    return Random(randM);
}
