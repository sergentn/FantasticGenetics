#ifndef MAXIMIZEONESFITNESSFUNCTION_HPP
#define MAXIMIZEONESFITNESSFUNCTION_HPP

#include "FitnessFunction.hpp"

class MaximizeOnesFitnessFunction : public FitnessFunction {
public:
    double computeFitness(Chromosome* solution, int chromosomesLength) override;

protected:
};

#endif