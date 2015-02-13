/*****************************  Interface.h  **********************************
* Author:        Brian W.
* Date created:  2015-02-08-12.55
* Last modified:
* Project:       BlackScholesModel
*
*
* Description:
* it helps the user to use the project's classes depending on what he or she wants
*
* Member attributes:
* ===========================
*
*
*
* Member functions (methods):
* ===========================
*
* Further documentation:
* ======================
*
*******************************************************************************/

#ifndef INTERFACE_H
#define INTERFACE_H
#include <string>
#include <queue>
#include "PayOffCall.h"
#include "PayOffPut.h"
#include "PayOffDigitalCall.h"
#include "PayOffDigitalPut.h"
#include "DiscountFactor.h"
#include "Binomial.h"
#include "BlackS.h"

using namespace std;
class Interface
{
    public:
        Interface(DiscountFactor& df);
        virtual ~Interface();

        void Clean_buffer();

        bool ChoiceOption(string& str);
        bool InOptions(const string& str);
        std::queue<string> getOptions(){return Options;}
        void deleteOneOption(){Options.pop();}
        void setOptions();

        bool ChoiceModel(string& str);
        bool InModels(string& str);
        std::queue<string> getModels(){return Models;}
        void deleteOneModel(){Models.pop();}
        void setModels();

        bool setPourcentage(double&);
        bool setDouble(double&,string);
        bool setInteger(int&,string);

        bool ChoiceDiscountFactorUsed(string& str);
        bool InDiscountFactorUsed(string& str);
        std::queue<string> getDiscountFactorUsed(){return DiscountFactorUsed;}
        void deleteOnDiscountFactorUsed(){DiscountFactorUsed.pop();}
        void setDiscountFactorUsed();

        void setUserPayoff(const string& User);
        PayOff* getUserPayoff(){return UserPayoffPtr;}

        void setUserDFPtr(const string& User);
        DiscountFactor* getUserDFPtr(){return UserDFPtr;}

        void setUserPricerModel(string& model);
        BlackS* getUserBlack(){return UserBlack;};
        Binomial* getUserBinomial(){return UserBinomial;}

		void SumUp(string& userpayoff,string& model);

    protected:
    private:
        queue<string> Options;
        queue<string> Models;
        queue<string> DiscountFactorUsed;
        PayOff* UserPayoffPtr;
        DiscountFactor* UserDFPtr;
        BlackS* UserBlack;
        Binomial* UserBinomial;
//        std::queue<string>

};

#endif // INTERFACE_H
