#ifndef POPULATION_HPP
#define POPULATION_HPP

#include <Chromosome.hpp>
#include <string>
#include <vector>

class Population {
public:
    Population();
    Population(int initialPopSize, int chromosomesLength);
    ~Population();
    std::vector<Chromosome*> getChromosomes();
    int getChromosomesLength();
    void setChromosomes(std::vector<Chromosome*> newChromosomes);
    int getPopulationSize();

protected:
    std::vector<Chromosome*> chromosomes;
};

#endif