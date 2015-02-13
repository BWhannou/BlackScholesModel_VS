/*****************************  BoxMuller.h  **********************************
* Author:        Brian W.
* Date created:  2015-02-08-12.55
* Last modified:
* Project:       BlackScholesModel
*
*
* Description:
* generates a normal distribution by transforming a set of uniform random numbers with the Box-Müller algorithm

* Member attributes:
* ===========================
*      double Mean;
*      double Sigma;
*
* Member functions (methods):
* ===========================
* the constructor and the destructor.
*
* the getters and setters of the attributes.
*
* virtual double Random(UniGen&): gives a random number which follows the N(Mean,Sigma) law
*
* Further documentation:
* ======================
* BlackScholesModel_WB.pdf
*******************************************************************************/

#ifndef BOXMULLER_H
#define BOXMULLER_H

#include "NormGen.h"
#include "UniGen.h"

class BoxMuller : public NormGen
{
    public:
        BoxMuller(double Mean_,double Sigma_ );
        virtual ~BoxMuller();

        double GetMean() { return Mean; }
        void SetMean(double val) { Mean = val; }
        double GetSigma() { return Sigma; }
        void SetSigma(double val) { Sigma = val; }

        virtual double Random(UniGen& theUniGen);
        virtual double Random();
    protected:
    private:
};

#endif // BOXMULLER_H
