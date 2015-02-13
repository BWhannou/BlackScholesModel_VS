/***************************** PayOffDigitalCall.h   **********************************
* Author:        Brian W.
* Date created:  2015-02-12-18.24$
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
*
*
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
*******************************************************************************/#ifndef PAYOFFDIGITALCALL_H
#define PAYOFFDIGITALCALL_H

#include "PayOff.h""


class PayOffDigitalCall : public PayOff
{
    public:
        PayOffDigitalCall(double Strike_, double FixedPayment);
        virtual ~PayOffDigitalCall();

        PayOffDigitalCall(const PayOffDigitalCall& other);

        PayOffDigitalCall& operator=(const PayOffDigitalCall& other);
        double GetStrike() { return Strike; }
        void SetStrike(double val) { Strike = val; }
        double GetFixedPayment() { return FixedPayment; }
        void SetFixedPayment(double val) { FixedPayment = val; }

        virtual PayOffDigitalCall* clone() const;

        double operator () (double spot) const;
    protected:
    private:
        double Strike;
        double FixedPayment;
};

#endif // PAYOFFDIGITALCALL_H
