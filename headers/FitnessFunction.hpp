#ifndef FITNESSFUNCTION_HPP
#define FITNESSFUNCTION_HPP

#include "Chromosome.hpp"

class FitnessFunction {
public:
    virtual double computeFitness(Chromosome* solution, int chromosomesLength);

protected:
};

#endif