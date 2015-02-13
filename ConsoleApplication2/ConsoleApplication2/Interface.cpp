#include "Interface.h"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>
#include "ActuarialDF.h"
#include "ContinuousDF.h"

using namespace std;
Interface::Interface(DiscountFactor& df)
{
    Options.push("Put");
    Options.push("Call");
    Options.push("DigitalCall");
    Options.push("DigitalPut");

    Models.push("Binomial");
    Models.push("BlackScholes");

    DiscountFactorUsed.push("Actuarial");
    DiscountFactorUsed.push("Continuous");


   UserBinomial=new Binomial(0.0,0.0,0.0,df);
    UserBlack=new BlackS(0.0,0.0,df);
    //ctor
}

Interface::~Interface()
{
    delete UserPayoffPtr;
    delete UserDFPtr;
    //dtor
}

void Interface::setOptions()
{
    Options.push("Put");
    Options.push("Call");
    Options.push("DigitalCall");
    Options.push("DigitalPut");

}

void Interface::setModels()
{
    Models.push("Binomial");
    Models.push("BlackScholes");
}

void Interface::setDiscountFactorUsed()
{
    DiscountFactorUsed.push("Actuarial");
    DiscountFactorUsed.push("Continuous");
}
void Interface::Clean_buffer()
{
    cin.clear();
    cin.seekg(0, ios::end);

    if(!cin.fail())
    {
        cin.ignore(numeric_limits<streamsize>::max()); // we don't need to use Clear()
    }

    else
    {
        cin.clear(); // it cleans the flow
    }
}

bool Interface::InOptions(const string& str)
{
    int n=Options.size();
    for (int i=0; i<n ; i++)
    {
        if(str==Options.front())
        {
            return true;
        }
        Options.pop();
    }
    return false;
}

bool Interface::InModels(string& str)
{
    int n=Models.size();
    for (int i=0; i<n ; i++)
    {
        if(str==Models.front())
        {
            return true;
        }
        Models.pop();
    }
    return false;
}

bool Interface::InDiscountFactorUsed(string& str)
{
    int n=DiscountFactorUsed.size();
    for (int i=0; i<n ; i++)
    {
        if(str==DiscountFactorUsed.front())
        {
            return true;
        }
        DiscountFactorUsed.pop();
    }
    return false;
}

bool Interface::ChoiceOption(string& str)
{
    while(true)
    {
        cout << "Which one do you want?"<<endl;
        getline(cin, str);

        if(!InOptions(str))
        {
            cerr << "please choose among the options above" << endl;
            setOptions();
            continue;
        }

        Clean_buffer();

        break;
    }
    return true;
}

bool Interface::ChoiceModel(string& str)
{
    while(true)
    {
        cout << "Which one do you want?"<<endl;
        getline(cin, str);

        if(!InModels(str))
        {
            cerr << "please choose among the models above" << endl;
            setModels();
            continue;
        }

        Clean_buffer();
        break;
    }
    return true;
}

bool Interface::ChoiceDiscountFactorUsed(string& str)
{
    while(true)
    {
        cout << "Which one do you want?"<<endl;
        getline(cin, str);

        if(!InDiscountFactorUsed(str))
        {
            cerr << "please choose among the discount factor above" << endl;
            setDiscountFactorUsed();
            continue;
        }

        Clean_buffer();
        break;
    }
    return true;
}

bool Interface::setDouble(double& number, string message)
{
    while(true)
    {
        cout << message<<endl;
        cin >> number;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "we need a double here " << endl;
			continue;
        }
        Clean_buffer();
        break;
    }
    return true;
}

bool Interface::setInteger(int& number, string message)
{
    while(true)
    {
        cout << message<<endl;
        cin >> number;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "we need an integer here " << endl;
            continue;
        }
        Clean_buffer();
        break;
    }
    return true;
}


bool Interface::setPourcentage(double& taux)
{
    while(true)
    {
        cout << "what is the risk less rate(e.g. give 0.5 for 50%)?" <<endl;
        cin >> taux;

        if(taux<0)
        {
            cerr << "please take a rate non-negative" << endl;
            continue;
        }
        else if (taux>1)
        {
            cerr << "please beware that a rate equals to 1 means 100%." <<"\n" <<"do you want to continue?(Yes/No)" << endl;
            string answer="Yes";
            cin >> answer;
            if (answer=="No")
            {
                continue;
            }
        }

        Clean_buffer();
        break;
    }
    return true;
}

void Interface::setUserPayoff(const string& User)
{
    if(InOptions(User))
    {
        double strike;
        setDouble(strike,"what is the strike?(a double)");
        if (User=="Call")
        {
            UserPayoffPtr=new PayOffCall(strike);
        }
        else if (User=="Put")
        {
            UserPayoffPtr=new PayOffPut(strike);
        }
        else if (User=="DigitalCall")
        {
            double fixedpayment;
            setDouble(fixedpayment,"what is the fixed payment of the option?(a double)");
            UserPayoffPtr=new PayOffDigitalCall(strike,fixedpayment);
        }
        else if (User=="DigitalPut")
        {
            double fixedpayment;
            setDouble(fixedpayment,"what is the fixed payment of the option?(a double)");
            UserPayoffPtr=new PayOffDigitalPut(strike,fixedpayment);
        }
    }
    else
    {
        cout << "we don't know this payoff yet..."<<endl;
    }
}



void Interface::setUserDFPtr(const string& User)
{
    if(User=="Actuarial"||User=="Continuous")
    {
        double maturity(0);
        double rate(0);
        setPourcentage(rate);
        if (User=="Actuarial")
        {
            UserDFPtr=new ActuarialDF(maturity,rate);
        }
        else
        {
            UserDFPtr=new ContinuousDF(maturity,rate);
        }
    }
    else
    {
        cout << "we don't know this discount factor yet..."<<endl;
    }
}

void Interface::setUserPricerModel(string& model)
{
    cout << "you choose the " << model << " model" << endl;
    cout << "let us set some parameters specific to that model"<< endl;
    cout << "what is  the first Spot?"<< endl;
    double firstSpot;
    cin >> firstSpot;
    if(model=="Binomial")
    {
        double up;
        double down;
        cout << "what is the \" up \" factor?(a double)" <<endl;
        cin >> up;

        cout << "what is the \"down \" factor?(a double)" << endl;
        cin >> down;

        UserBinomial=new Binomial(up,down,firstSpot,*UserDFPtr);
    }
    else if (model=="BlackScholes")
    {
        double volatility;
        cout << "what is the volatility?"<< endl;
        cin>>volatility;
        UserBlack=new BlackS(volatility,firstSpot,*UserDFPtr);
    }
    else
    {
        cout << "we don't know this discount factor yet..."<<endl;
    }


}


void Interface::SumUp(string& userpayoff,string& themodel)
{
	cout << "Finally, You choose to price a "<< userpayoff << "using the model "<<endl;
	cout << themodel <<" .The interest rate is "<< UserDFPtr->GetRate()<< " and"<< endl;
	cout << "the maturity is "<<UserDFPtr->GetMaturity()<<endl;
}


