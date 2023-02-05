#ifndef BESTOF_SELECTION_HPP
#define BESTOF_SELECTION_HPP

#include <vector>

#include "SelectionOperator.hpp"

#include "Chromosome.hpp"
#include "FitnessFunction.hpp"

class BestOfSelection : public SelectionOperator {
public:
    BestOfSelection(int numberOfSolutionsToSelect);
    void doSelection(Population* solutions, FitnessFunction* fitnessFunction, int chromosomesLength) override;

protected:
    int numberOfSolutionsToSelect;
};

#endif