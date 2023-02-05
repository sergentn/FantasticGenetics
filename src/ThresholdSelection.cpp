#include "ThresholdSelection.hpp"

#include <iostream>
#include <vector>

#include "Chromosome.hpp"

ThresholdSelection::ThresholdSelection(double fitnessThreshold)
{
    this->fitnessThreshold = fitnessThreshold;
}

void ThresholdSelection::doSelection(Population* solutions, FitnessFunction* fitnessFunction, int chromosomesLength)
{
    std::cout << "Selecting solutions now (thresholdSelection method) !" << std::endl;
    std::vector<Chromosome*> selectedSolutions;

    for (Chromosome* candidate : solutions->getChromosomes()) {
        double fitness = fitnessFunction->computeFitness(candidate, chromosomesLength);

        if (fitness >= this->fitnessThreshold) {
            selectedSolutions.push_back(candidate);
            std::cout << "Selected solution : " << candidate->getSequence() << " (fitness: " << fitness << ")" << std::endl;
        } else {
            std::cout << "Rejected solution : " << candidate->getSequence() << " (fitness: " << fitness << ")" << std::endl;
            delete candidate;
        }
    }

    solutions->setChromosomes(selectedSolutions);
}