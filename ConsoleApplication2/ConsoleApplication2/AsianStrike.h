/*****************************    **********************************
* Author:        Brian W.
* Date created:  2015-02-12-21.30$
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
*******************************************************************************/#ifndef ASIANSTRIKE_H
#define ASIANSTRIKE_H

#include "AsianPayOff.h"


class AsianStrike : public AsianPayOff
{
    public:
        AsianStrike();
        virtual ~AsianStrike();
        AsianStrike(const AsianStrike& other);
        AsianStrike& operator=(const AsianStrike& other);
        double Getstrike() { return strike; }
        void Setstrike(double val) { strike = val; }
    protected:
    private:
        double strike;
};

#endif // ASIANSTRIKE_H
