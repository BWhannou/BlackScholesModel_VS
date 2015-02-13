#include <iostream>
#include "ActuarialDF.h"
#include"ContinuousDF.h"
#include "PayOffCall.h"
#include "randomc.h"
#include "Interface.h"
#include <math.h>
#include "Option.h"

using namespace std;

int main()
{

	int start=1;

	while (start==1){


      ActuarialDF df1(0,0);

    Interface inter(df1);
    string optionstr;
    string model;
    string df;
    double maturity;


    cout << "the options we can price are:"<< endl;
    int n=inter.getOptions().size();
    for (int i=0; i<n ; i++)
    {
        cout << inter.getOptions().front() << endl;
        inter.deleteOneOption();

    }
    inter.setOptions();
    inter.ChoiceOption(optionstr);

    cout << optionstr<<endl ;
    inter.setUserPayoff(optionstr);



    cout << "We can use one of these models:" << endl;
    n=inter.getModels().size();
    for (int i=0; i<n ; i++)
    {
        cout << inter.getModels().front() << endl;
        inter.deleteOneModel();

    }
    inter.setModels();

    inter.ChoiceModel(model);
    cout << model<<endl;

    if (model=="Binomial")
    {
        int mat;
        inter.setInteger(mat,"what is the maturity of the option?(an integer)");
        maturity=(double)mat;

    }
    else if (model=="BlackScholes")
    {
        inter.setDouble(maturity,"what is the maturity of the option?(a float)");
    }
    cout << maturity << endl;

    cout << "We can use one of these discount Factor:" << endl;
    n=inter.getDiscountFactorUsed().size();
    for (int i=0; i<n ; i++)
    {
        cout << inter.getDiscountFactorUsed().front() << endl;
        inter.deleteOnDiscountFactorUsed();

    }
    inter.setDiscountFactorUsed();

    inter.ChoiceDiscountFactorUsed(df);
    cout << df<<endl;
    inter.setUserDFPtr(df);
    inter.getUserDFPtr()->SetMaturity(maturity);


    Option option(*(inter.getUserPayoff()),maturity);
    cout<< option.GetMaturity()<<endl;

	inter.setUserPricerModel(model);

	inter.SumUp(optionstr,model);


    if (model=="Binomial")
    {
        cout<<(double)inter.getUserBinomial()->Price(option)<< endl;
    }
    else if (model=="BlackScholes")
    {
        cout << inter.getUserBlack()->PriceMersenne(option,100000000,1235)<<endl;
		cout << "the Standard error is "<<inter.getUserBlack()->GetStdE()<<endl;
		cout << "the number of iterations "<<inter.getUserBlack()->GetLoop()<<endl;
    }
   

	cout << "do you want to start again ? yes=1"<<endl;
	cin>> start;
	}
    return 0;
}
