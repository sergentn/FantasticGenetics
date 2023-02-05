#ifndef THRESHOLD_SELECTION_HPP
#define THRESHOLD_SELECTION_HPP

#include <vector>

#include "SelectionOperator.hpp"

#include "Chromosome.hpp"
#include "FitnessFunction.hpp"

class ThresholdSelection : public SelectionOperator {
public:
    ThresholdSelection(double fitnessThreshold);
    void doSelection(Population* solutions, FitnessFunction* fitnessFunction, int chromosomesLength) override;

protected:
    double fitnessThreshold;
};

#endif