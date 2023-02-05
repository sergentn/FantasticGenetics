#ifndef CROSSOVEROPERATOR_HPP
#define CROSSOVEROPERATOR_HPP

#include <vector>

#include "Chromosome.hpp"
#include "Population.hpp"

class CrossoverOperator {
public:
    virtual void doCrossover(Population* parents);

protected:
};

#endif