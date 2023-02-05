#include "MutationOperator.hpp"

#include <iostream>
#include <string>
#include <vector>

#include "Population.hpp"

// Invert only one bit in the chromosome sequence
void MutationOperator::singleBitMutation(Chromosome* chromosome)
{
    std::string seq = chromosome->getSequence();

    int randomPos = rand() % seq.length(); // 0 <= this < seq.length()

    std::cout << "RANDOM POS : " << randomPos << std::endl;
    std::cout << "Previous sequence = " << seq;

    // Invert the bit at random position TODO : more elegant way is possible ?
    if (seq[randomPos] == '1')
        seq[randomPos] = '0';
    else if (seq[randomPos] == '0')
        seq[randomPos] = '1';

    std::cout << ", new sequence = " << seq << std::endl;

    chromosome->setSequence(seq);
}

void MutationOperator::mutatePopulaton(Population* solutions, int mutationChancePercent)
{
    for (Chromosome* sol : solutions->getChromosomes()) {
        bool doWeMutate = (rand() % 100) <= mutationChancePercent; // between 0 and 100 ?
        if (doWeMutate) {
            this->singleBitMutation(sol);
        }
    }
}