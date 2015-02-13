#ifndef PAYOFFCALL_H
#define PAYOFFCALL_H

#include "PayOff.h"


class PayOffCall : public PayOff
{
    public:
        PayOffCall(double Strike_);
        virtual ~PayOffCall();

        PayOffCall(const PayOffCall& other);

        PayOffCall& operator=(const PayOffCall& other);  //assignement  operator
        double GetStrike() { return Strike; }
        void SetStrike(double val) { Strike = val; }

        virtual double operator() (double Spot) const;
        virtual PayOffCall* clone() const;

    protected:
    private:
        double Strike;
};

#endif // PAYOFFCALL_H
