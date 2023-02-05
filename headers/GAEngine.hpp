#ifndef GAENGINE_HPP
#define GAENGINE_HPP

#include <vector>

#include "Enums.hpp"

#include "Chromosome.hpp"
#include "Population.hpp"
#include "CrossoverOperator.hpp"
#include "FitnessFunction.hpp"
#include "MutationOperator.hpp"
#include "SelectionOperator.hpp"

class GAEngine {
public:
    GAEngine(int iterationsNb, int chromosomesLength, int initialPopSize, double fitnessThreshold, int bestOfNumber, int mutationChancePercent, EFitnessFunction, ECrossoverOperator, ESelectionMethod);

    std::vector<Chromosome*> generateInitialPopulation();
    std::vector<Chromosome*> removeDuplicates();
    std::vector<Chromosome*> evaluateSolutions();

    void process();
    void displayFinalRanking();

protected:
    int iterationsNb;
    int chromosomesLength;
    int initialPopSize;
    double fitnessThreshold;
    int bestOfNumber;
    int mutationChancePercent;

    FitnessFunction* fitnessFunction;
    CrossoverOperator* crossoverOperator;
    MutationOperator* mutationOperator;
    SelectionOperator* selectionOperator;

    //std::vector<Chromosome*> solutions;
    Population* population;
};

#endif