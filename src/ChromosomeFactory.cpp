#include "ChromosomeFactory.hpp"

#include <iostream>
#include <string>

#include "Chromosome.hpp"

Chromosome* ChromosomeFactory::newChromosome(std::string sequence) {
    return new Chromosome(sequence);
}

Chromosome* ChromosomeFactory::newRandomChromosome(int length) {
    std::string sequence = "";

    for (int i = 0; i < length; i++) {
        double rd = (float)rand() / RAND_MAX;  // float between 0 and 1
        sequence += (rd < 0.5) ? '0' : '1';
    }
    Chromosome* newChr = new Chromosome(sequence);
    std::cout << "ChromosomeFactory: new sequence = " << newChr->getSequence() << std::endl;
    return newChr;
}
