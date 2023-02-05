#include "SelectionOperator.hpp"

#include <iostream>
#include <map>
#include <vector>

#include "FitnessFunction.hpp"
#include "Population.hpp"

void SelectionOperator::removeDuplicates(Population* solutions)
{
    std::cout << "Removing duplicates among solutions..." << std::endl;
    std::vector<Chromosome*> solutionsWoDupl;

    // TODO : More efficient way ?
    for (Chromosome* solution : solutions->getChromosomes()) {
        bool duplicateFound = false;

        for (Chromosome* newSolution : solutionsWoDupl) {
            if (solution->getSequence() == newSolution->getSequence()) {
                duplicateFound = true;
            }
        }

        if (duplicateFound == false) {
            solutionsWoDupl.push_back(solution);
        } else {
            delete solution;
        }
    }
    solutions->setChromosomes(solutionsWoDupl);
}

void SelectionOperator::doSelection(Population* solutions, FitnessFunction* fitnessFunction, int chromosomesLength)
{
    // Implementation in derived classes
}