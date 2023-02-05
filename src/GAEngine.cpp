#include "GAEngine.hpp"

#include <iostream>
#include <vector>

#include "Chromosome.hpp"
#include "ChromosomeFactory.hpp"
#include "MaximizeOnesFitnessFunction.hpp"
#include "MutationOperator.hpp"
#include "SinglepointCrossover.hpp"
#include "ThresholdSelection.hpp"
#include "BestOfSelection.hpp"
#include "Population.hpp"

#include "Enums.hpp"

GAEngine::GAEngine(int iterationsNb, int chromosomesLength, int initialPopSize, double fitnessThreshold, int bestOfNumber, int mutationChancePercent, EFitnessFunction fitnessFunction, ECrossoverOperator crossoverOperator, ESelectionMethod selectionMethod)
{
    this->iterationsNb = iterationsNb;
    this->chromosomesLength = chromosomesLength;
    this->initialPopSize = initialPopSize;
    this->fitnessThreshold = fitnessThreshold;
    this->bestOfNumber = bestOfNumber;
    this->mutationChancePercent = mutationChancePercent;

    std::cout << "GAEngine: New simulation !" << std::endl;

    switch (fitnessFunction) {
    case EFitnessFunction::MAXIMIZE_ONES:
        this->fitnessFunction = new MaximizeOnesFitnessFunction();
        std::cout << "GAEngine: FitnessFunction is MaximizeOnesFitnessFunction" << std::endl;
        break;
    default:
        this->fitnessFunction = new MaximizeOnesFitnessFunction();
        std::cout << "GAEngine: FitnessFunction is MaximizeOnesFitnessFunction (default)" << std::endl;
        break;
    }

    switch (crossoverOperator) {
    case ECrossoverOperator::SINGLEPOINT:
        this->crossoverOperator = new SinglepointCrossover();
        std::cout << "GAEngine: CrossOverOperator is SinglepointCrossover" << std::endl;
        break;
    default:
        this->crossoverOperator = new SinglepointCrossover();
        std::cout << "GAEngine: CrossOverOperator is SinglepointCrossover (default)" << std::endl;
        break;
    }

    switch (selectionMethod) {
    case ESelectionMethod::THRESHOLD:
        this->selectionOperator = new ThresholdSelection(fitnessThreshold);
        std::cout << "GAEngine: SelectionMethod is ThresholdSelection" << std::endl;
        break;
    case ESelectionMethod::BESTOF:
        this->selectionOperator = new BestOfSelection(bestOfNumber);
        std::cout << "GAEngine: SelectionMethod is BestOfSelection" << std::endl;
        break;
    default:
        this->selectionOperator = new ThresholdSelection(fitnessThreshold);
        std::cout << "GAEngine: SelectionMethod is ThresholdSelection (default)" << std::endl;
        break;
    }

    // By default, create a mutation operator
    this->mutationOperator = new MutationOperator();
}

void GAEngine::process()
{
    std::cout << "GAEngine: Number of iterations: " << this->iterationsNb << std::endl;
    std::cout << "GAEngine: Chromosomes length: " << this->chromosomesLength << std::endl;
    std::cout << "GAEngine: Initial population size: " << this->initialPopSize << std::endl;
    std::cout << "GAEngine: Fitness threshold: " << this->fitnessThreshold << std::endl;
    std::cout << "GAEngine: Best of number: " << this->bestOfNumber << std::endl;
    std::cout << "GAEngine: Percentage chance of mutation: " << this->mutationChancePercent << std::endl;

    this->population = new Population(this->initialPopSize, this->chromosomesLength);

    for (Chromosome* solution : this->population->getChromosomes())
        std::cout << "Initial sequence: " << solution->getSequence() << std::endl;

    // Main loop
    for (int i = 0; i < this->iterationsNb; i++) {

        // Crossover
        std::cout << std::endl;
        std::cout << "===== ITERATION N°" << i << " =====" << std::endl;
        std::cout << "--------------------" << std::endl;
        std::cout << "Crossover phase..." << std::endl;
        this->crossoverOperator->doCrossover(this->population);

        // Mutation
        this->mutationOperator->mutatePopulaton(this->population, this->mutationChancePercent);

        // Select solutions
        std::cout << "--------------------" << std::endl;
        std::cout << "Selection phase..." << std::endl;
        this->selectionOperator->removeDuplicates(this->population);
        this->selectionOperator->doSelection(this->population, this->fitnessFunction, this->chromosomesLength);
    }
}


void GAEngine::displayFinalRanking()
{
    std::cout << "--------------------" << std::endl;
    std::cout << "Final results:" << std::endl;
    for (Chromosome* finalSol : this->population->getChromosomes()) {
        std::cout << finalSol->getSequence() << " rating: " << this->fitnessFunction->computeFitness(finalSol, this->chromosomesLength) << std::endl;
    }
}