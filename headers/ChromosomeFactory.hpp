#ifndef CHROMOSOMEFACTORY_HPP
#define CHROMOSOMEFACTORY_HPP

#include <string>

#include "Chromosome.hpp"

class ChromosomeFactory
{
public:
    ChromosomeFactory();
    static Chromosome* newChromosome(std::string sequence);
    static Chromosome* newRandomChromosome(int length);

protected:

};

#endif