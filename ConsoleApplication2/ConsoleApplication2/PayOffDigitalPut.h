/*****************************  PayOffDigitalPut.h  **********************************
* Author:        Brian W.
* Date created:  2015-02-12-18.14$
* Last modified:
* Project:       BlackScholesModel$
*
*
* Description:
*
*
*
* Member attributes:
* ===========================
*
*
* double Strike;
* double FixedPayment: if the stock value is beneath the strike, the buyer of the option gets the Fixed Payment
*
*
* Member functions (methods):
* ===========================
*
*
*
*
*
*
*
* Further documentation:
* ======================
*
*******************************************************************************/
#ifndef PAYOFFDIGITALPUT_H
#define PAYOFFDIGITALPUT_H

#include "PayOff.h"


class PayOffDigitalPut : public PayOff
{
    public:
        PayOffDigitalPut(double,double);
        virtual ~PayOffDigitalPut();

        PayOffDigitalPut(const PayOffDigitalPut& other);

        PayOffDigitalPut& operator=(const PayOffDigitalPut& other);

        double GetStrike() { return Strike; }
        void SetStrike(double val) { Strike = val; }
        double GetFixedPayment() { return FixedPayment; }
        void SetFixedPayment(double val) { FixedPayment = val; }

        virtual PayOffDigitalPut* clone() const;

        double operator() (double Spot)const;
    protected:
    private:
        double Strike;
        double FixedPayment;
};

#endif // PAYOFFDIGITALPUT_H
