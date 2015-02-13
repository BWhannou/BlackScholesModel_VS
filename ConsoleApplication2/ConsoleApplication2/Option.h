#ifndef OPTION_H
#define OPTION_H

#include "PayOff.h"

class Option
{
    public:
        Option(PayOff& MyPayOff_,double Maturity_);
//        Option(PayOff* MyPayOffPtr_,double Maturity_){MyPayOffPtr=MyPayOffPtr_; Maturity=Maturity_;};
        virtual ~Option();

        Option(const Option& other);
        Option& operator=(const Option& other);

        double GetMaturity() const { return Maturity; }
        void SetMaturity(double val) { Maturity = val; }
        PayOff* GetMyPayOffPtr() const { return MyPayOffPtr; }
        void SetMyPayOff(PayOff* val) { MyPayOffPtr = val; }

        double OptionPayOff(double Spot) const;
    protected:
    private:
        double Maturity;
        PayOff* MyPayOffPtr;
        /*the option is defined by its maturity and by its Payoff. The Payoff is defined out of the option's class.
        so in order to keep option's class independent from the outside, one of its values is a pointer to one copy of payoff*/
};

#endif // OPTION_H
