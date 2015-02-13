#include "Binomial.h"
#include <iostream>
#include <math.h>

using namespace std;

Binomial::Binomial(double up_,double down_,double firstSpot_,const DiscountFactor& theDF_):
    up(up_), down(down_), firstSpot(firstSpot_)
{
    MyDFPtr=theDF_.Clone();
    //ctor
}

//Binomial::Binomial(double up_,double down_,double firstSpot_,DiscountFactor* theDFPtr_):
//    up(up_), down(down_), firstSpot(firstSpot_)
//{
//    MyDFPtr=theDFPtr_;
//}

double Binomial::RiskNeutralProb() const
{
    double R=MyDFPtr->GetRate();
    //return (exp(rate)-down)/(up-down);
	return (1+R-down)/(up-down);
}
std::queue<double> Binomial::Graph() const
{
    std::queue<double> current, lowerLevel;  // current represents the ith level
    current.push(up);                  //we seek to find the lower level ((i+1)th level)
    current.push(down);
    double Time=MyDFPtr->GetMaturity();
    for (int i=1;i<Time;i++)
    {
        int lengthCurrent=current.size();
        for (int j=0;j<lengthCurrent;j++) //we are building lowerLevel
        {
            double upCase=current.front()*up;
            double downCase=current.front()*down;
            lowerLevel.push(upCase);
            lowerLevel.push(downCase);
            current.pop();
        }                                              //current is empty
        int lengthLowerLevel=lowerLevel.size();
        for (int m=0;m<lengthLowerLevel;m++)
        {
            current.push(lowerLevel.front());
            lowerLevel.pop();
        }                                               // current takes the value of the lower level
                                                                //lowerLevel is empty
    }
    std::queue<double> result;
    int lengthCurrent=current.size();
    for (int k=0;k<lengthCurrent;k++)
    {
        double spot=firstSpot*current.front();
        result.push(spot);
        current.pop();
    }
    return result;
}
Binomial::~Binomial()
{
    delete MyDFPtr;
    //dtor
}

Binomial& Binomial::operator=(const Binomial& rhs)
{
    if (this != &rhs)
    {
        up=rhs.up;
        down=rhs.down;
        firstSpot=rhs.firstSpot;
        delete MyDFPtr;
        MyDFPtr=rhs.MyDFPtr->Clone();
    } // handle self assignment
    //assignment operator
    return *this;
}

std::queue<double> Binomial::OptionGraph(const Option& theOption)   //evaluate the payoff of a set of underlying's values
{
	std::queue<double> graph=Graph();
	std::queue<double> result;
	int lengthGraph=graph.size();
	for (int i=0;i<lengthGraph;i++)
    {
        result.push(theOption.OptionPayOff(graph.front()));
        graph.pop();
    }
    return result;
}

double Binomial::Price(const Option& theOption)
{
    std::queue<double> graph=OptionGraph(theOption);
    std::queue<double> currentValue;
    double pb=RiskNeutralProb();
    double Time=MyDFPtr->GetMaturity();
    for (int j=0; j<Time;j++)
    {

        int lengthGraph=graph.size();
        for(int i=0; i< lengthGraph;i+=2)
        {
            double upCase=graph.front();
            graph.pop();
            double downCase=graph.front();
            graph.pop();
            //double upCaseValue(theOption.Payoff(upCase)), downCaseValue(theOption.Payoff(downCase));
            double optionValue;
            optionValue=(pb*upCase+(1-pb)*downCase);
            //optionValue=(exp(-rate))*(pb*upCase+(1-pb)*downCase);
			//cout <<"optionValue"<< optionValue<< endl;
            currentValue.push(optionValue);
        }
        int lengthCurrent=currentValue.size();
        for (int k=0; k<lengthCurrent; k++)
        {
			//cout << "currentValue"<< currentValue.front();
            graph.push(currentValue.front());
            currentValue.pop();
			//cout << "graph"<< graph.back();
        }
    }
	//cout << graph.size();
    return (MyDFPtr->DF())*graph.front();
}

//this is an European binomial option
