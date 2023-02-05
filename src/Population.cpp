#include "Population.hpp"

#include "ChromosomeFactory.hpp"

Population::Population()
{
}

Population::Population(int initialPopSize, int chromosomesLength)
{
    for (int i = 0; i < initialPopSize; i++) {
        Chromosome* newChr = ChromosomeFactory::newRandomChromosome(chromosomesLength);
        this->chromosomes.push_back(newChr);
    }
}

Population::~Population()
{
    for (Chromosome* cr : this->chromosomes) {
        delete cr;
    }
}

std::vector<Chromosome*> Population::getChromosomes()
{
    return this->chromosomes;
}

void Population::setChromosomes(std::vector<Chromosome*> newChromosomes) {
    this->chromosomes = newChromosomes;
}

// Implementation could be different if we store popSize and chromosomesLength

int Population::getPopulationSize()
{
    return this->chromosomes.size();
}

int Population::getChromosomesLength()
{
    int length = 0;
    if (this->getPopulationSize() > 0)
        length = this->chromosomes[0]->getSequence().length(); // all chromosomes have the same length

    return length;
}
