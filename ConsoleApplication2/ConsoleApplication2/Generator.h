#ifndef GENERATOR_H
#define GENERATOR_H


class Generator
{
    public:
        Generator();
        virtual ~Generator();
        virtual double Random()=0;
    protected:
    private:
};

#endif // GENERATOR_H
