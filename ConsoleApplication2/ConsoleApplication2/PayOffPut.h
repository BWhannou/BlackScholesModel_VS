#ifndef PAYOFFPUT_H
#define PAYOFFPUT_H

#include "PayOff.h"


class PayOffPut : public PayOff
{
    public:
        PayOffPut(double Strike_);
        virtual ~PayOffPut();
        PayOffPut(const PayOffPut& other);
        PayOffPut& operator=(const PayOffPut& other);
        double GetStrike() { return Strike; }
        void SetStrike(double val) { Strike = val; }

        virtual double operator() (double Spot) const;
        virtual PayOffPut* clone() const;
    protected:
    private:
        double Strike;
};

#endif // PAYOFFPUT_H
