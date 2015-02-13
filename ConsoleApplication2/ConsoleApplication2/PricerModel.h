#ifndef PRICERMODEL_H
#define PRICERMODEL_H

#include "Option.h"
class PricerModel
{
    public:
        PricerModel();
        virtual ~PricerModel();
        virtual double Price(const Option&)=0;
    protected:
    private:
};

#endif // PRICERMODEL_H
