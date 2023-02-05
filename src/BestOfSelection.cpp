#include "BestOfSelection.hpp"

#include <iostream>
#include <map>
#include <vector>

#include "Chromosome.hpp"

BestOfSelection::BestOfSelection(int numberOfSolutionsToSelect)
{
    this->numberOfSolutionsToSelect = numberOfSolutionsToSelect;
}

void BestOfSelection::doSelection(Population* solutions, FitnessFunction* fitnessFunction, int chromosomesLength)
{
    std::vector<Chromosome*> selectedSolutions;
    std::multimap<double, Chromosome*, std::greater<double>> sortedSolutions; // map allowing duplicates on key, descending sort on key

    std::cout << "Selecting solutions now (bestOfSelection method) !" << std::endl;

    for (Chromosome* solution : solutions->getChromosomes()) {
        double fitness = fitnessFunction->computeFitness(solution, chromosomesLength);
        sortedSolutions.insert({ fitness, solution });
    }

    // Take the "numberOfSolutionsToSelect" best
    std::multimap<double, Chromosome*>::iterator it = sortedSolutions.begin();
    int i = 0;

    while ((it != sortedSolutions.end()) && (i < this->numberOfSolutionsToSelect)) {
        std::cout << "BEST SOL n°" << i << " : " << it->second->getSequence() << ", score = " << it->first << std::endl;

        selectedSolutions.push_back(it->second);

        it++; // increment map operator
        i++; // increment loop counter
    }

    solutions->setChromosomes(selectedSolutions);
}