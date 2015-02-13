#ifndef NORMGEN_H
#define NORMGEN_H
#include "UniGen.h"
#include "Generator.h"


class NormGen : public Generator
{
    public:
        NormGen(double Mean_,double Sigma_ );
        NormGen();
        virtual ~NormGen();
        double GetMean() { return Mean; }
        void SetMean(double val) { Mean = val; }
        double GetSigma() { return Sigma; }
        void SetSigma(double val) { Sigma = val; }

         virtual double Random(UniGen&)=0;
    protected:
		double Mean;
        double Sigma;

    private:


};

#endif // NORMGEN_H
