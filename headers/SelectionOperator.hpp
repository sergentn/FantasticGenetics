#ifndef SELECTIONOPERATOR_HPP
#define SELECTIONOPERATOR_HPP

#include <vector>

#include "Chromosome.hpp"
#include "FitnessFunction.hpp"
#include "Population.hpp"

class SelectionOperator {
public:
    void removeDuplicates(Population* solutions);
    virtual void doSelection(Population* solutions, FitnessFunction* fitnessFunction, int chromosomesLength);

protected:
};

#endif