#ifndef UNIGEN_H
#define UNIGEN_H

#include "Generator.h"


class UniGen : public Generator
{
    public:
        UniGen();
        virtual ~UniGen();
        virtual double Random()=0;
    protected:
    private:
};

#endif // UNIGEN_H
