#ifndef UNIGENLC_H
#define UNIGENLC_H

#include "UniGen.h"


class UniGenLC : public UniGen
{
    public:
        UniGenLC(double Seed_);
        virtual ~UniGenLC();

        double GetSeed() { return Seed; }
        void SetSeed(double val) { Seed = val; }

        double GetCurrent() { return Current; }
        void SetCurrent(double val) { Current = val; }
        virtual double Random();
    protected:
    private:
        double Seed;
        double Current;
};

#endif // UNIGENLC_H
