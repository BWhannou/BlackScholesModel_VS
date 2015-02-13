#include "BlackS.h"
#include <math.h>
#include "BoxMuller.h"
#include "ContinuousTime.h"
#include "time.h"
#include "MonteCarlo.h"
#include "randomc.h"
#include <iostream>

BlackS::BlackS(double Volatility_,double FirstSpot_,DiscountFactor& theDF):
    Volatility(Volatility_), FirstSpot(FirstSpot_)
{
    //ctor
    MyDFPtr=theDF.Clone();
}

//BlackS::BlackS(double Volatility_,double FirstSpot_,DiscountFactor* theDFPtr_):
//    Volatility(Volatility_), FirstSpot(FirstSpot_), MyDFPtr(theDFPtr_)
//    {
//
//    }
BlackS::~BlackS()
{
    delete MyDFPtr;
    //dtor
}

BlackS& BlackS::operator=(const BlackS& rhs)
{
    if (this != &rhs)
    {
        Volatility=rhs.Volatility;
        FirstSpot=rhs.FirstSpot;
        delete MyDFPtr;
        MyDFPtr=rhs.MyDFPtr->Clone();
    } // handle self assignment
    //assignment operator
    return *this;
}

double BlackS::GetOneStockValue(UniGen& theUniGen_) const
{

    double rate=MyDFPtr->GetRate();
    double time=MyDFPtr->GetMaturity();
	double x = rate*time-0.5*Volatility*Volatility*time ;
    double spot=FirstSpot*exp(x);

    BoxMuller theBox(0,Volatility*sqrt(time));

    double A=exp(theBox.Random(theUniGen_));

    spot=spot*A;

    return spot;
}

double BlackS::GetPayOffValue(Option& theOption_,UniGen& theUniGen_)const
{
  
    return theOption_.OptionPayOff(GetOneStockValue(theUniGen_));
}

double BlackS::PriceMersenne(Option& theOption_,int stopCriteria_,int seed)
{
    CRandomMersenne rand1(seed);

    MonteCarlo MC;
    do
    {
        double result=GetPayOffValue(theOption_,rand1);
        MC.UpDate(result);
    }
    while
    (MC.GetLoop()<stopCriteria_);
    StdE=MC.EStdE();
	Loop=MC.GetLoop();

    return (MyDFPtr->DF())*MC.Mean();


}


double BlackS::PriceMersenne(Option& theOption_,double stopCriteria_,int seed)
{
    CRandomMersenne rand1(seed);

    MonteCarlo MC;
    double result=GetPayOffValue(theOption_,rand1);
    MC.UpDate(result);
    do
    {
        double result=GetPayOffValue(theOption_,rand1);
        MC.UpDate(result);
    }
    while
    (MC.EStdE() >=stopCriteria_);
    StdE=MC.EStdE();

    return (MyDFPtr->DF())*MC.Mean();


}
