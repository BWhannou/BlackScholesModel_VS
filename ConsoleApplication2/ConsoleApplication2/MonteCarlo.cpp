/**************************      **********************************
* Author:        Brian
* Date created:  2015-02-08-12.55
* Last modified:
* Project:       BlackScholesModel
* Platform:      Any C++
* Description:
*
*
*
*
*
*******************************************************************************/
#include "MonteCarlo.h"
#include "math.h"

MonteCarlo::MonteCarlo():Loop(0),Sum(0.0)
{

    //ctor
}

MonteCarlo::~MonteCarlo()
{
    //dtor
}

void MonteCarlo::UpDate(double result_)
{
    Sum=Sum+result_;
    Loop++;
    Results.push(result_);
}

double MonteCarlo::Mean()
{
    return (double)(Sum/Loop);
}

double MonteCarlo::EStdE()
{
    if (Results.size()<=1)
    {
        return 10000000;
    }
    double mean(Mean());
    double stdE(0);
    for (int i=1;i<=Loop;i++)
    {
        stdE=stdE+(Results.top()-mean)*(Results.top()-mean);
        Results.pop();
    }
    stdE=stdE/(Loop-1);
    stdE=sqrt(stdE);
    return stdE;
}
