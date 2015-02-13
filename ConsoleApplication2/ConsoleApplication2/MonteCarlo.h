/*****************************    **********************************
* Author:        Brian W.
* Date created:  2015-02-08-12.55
* Last modified:
* Project:       BlackScholesModel
*
*
* Description:
*
*
*
* Member attributes:
* ===========================
* double Sum
* the running sum of the results that will be estimate
*
* int Loop
* the number of Loops
*
* Member functions (methods):
* ===========================
*
* UpDate(double result):
* it updates the variables Sum and Loop, and stores the result
*
* Mean():
* EStdE(): Estimate Standard Error
*
* Further documentation:
* ======================
*
*******************************************************************************/
#ifndef MONTECARLO_H
#define MONTECARLO_H

#include <stack>
using namespace std;

class MonteCarlo
{
    public:
        MonteCarlo();
        virtual ~MonteCarlo();
        double GetSum() { return Sum; }
        void SetSum(double val) { Sum = val; }
        int GetLoop() { return Loop; }
        void SetLoop(int val) { Loop = val; }

        void UpDate(double result_);
        double Mean();
        double EStdE();

    protected:
    private:
        double Sum;
        int Loop;
        stack<double> Results;
};

#endif // MONTECARLO_H
