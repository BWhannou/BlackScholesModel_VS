/*****************************  AsianPayOff.h  **********************************
* Author:        Brian W.
* Date created:  2015-02-12-19.43$
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
*******************************************************************************/#ifndef ASIANPAYOFF_H
#define ASIANPAYOFF_H

#include "PayOff.h"


class AsianPayOff : public PayOff
{
    public:
        AsianPayOff();
        virtual ~AsianPayOff();
        int GetNumberOfDates() { return NumberOfDates; }
        void SetNumberOfDates(int val) { NumberOfDates = val; }
    protected:
    private:
        int NumberOfDates;
};

#endif // ASIANPAYOFF_H
