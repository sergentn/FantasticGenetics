#include "MaximizeOnesFitnessFunction.hpp"

#include "Chromosome.hpp"

// Really easy : most 1 in the sequence wins
double MaximizeOnesFitnessFunction::computeFitness(Chromosome* solution, int chromosomesLength)
{
    int numberOfOnes = 0;
    std::string seq = solution->getSequence();

    for (int i = 0; i < seq.length(); i++)
        if (seq[i] == '1')
            numberOfOnes++;

    return numberOfOnes / (double)chromosomesLength; // cast one of the two int to double in order to get a double returned
}