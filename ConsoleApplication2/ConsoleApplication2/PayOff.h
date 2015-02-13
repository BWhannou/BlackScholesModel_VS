#ifndef PAYOFF_H
#define PAYOFF_H


class PayOff
{
    public:
        PayOff();
        virtual ~PayOff();
        virtual double operator() (double Spot) const=0;
        // this class will look like a function giving
//the payoff of an option. it is one of the two option's characteristics
        virtual PayOff* clone() const=0;
    protected:
    private:
};

#endif // PAYOFF_H
