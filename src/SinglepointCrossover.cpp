#include "SinglepointCrossover.hpp"

#include <iostream>
#include <vector>

#include "Chromosome.hpp"
#include "Population.hpp"

void SinglepointCrossover::doCrossover(Population* parents)
{
    int chromosomesLength = parents->getChromosomesLength();
    std::vector<Chromosome*> children;

    // ---------- Single Point crossover between all the parents
    for (Chromosome* firstParent : parents->getChromosomes()) {
        for (Chromosome* secondParent : parents->getChromosomes()) {

            int randomPos = rand() % chromosomesLength; // 0 <= randomPos < chromosomesLength

            std::string parent1FirstGene = firstParent->getSequence().substr(0, randomPos);
            std::string parent2FirstGene = secondParent->getSequence().substr(0, randomPos);

            std::string parent1SecondGene = firstParent->getSequence().substr(randomPos, chromosomesLength);
            std::string parent2SecondGene = secondParent->getSequence().substr(randomPos, chromosomesLength);

            std::string newGene1 = parent1FirstGene + parent2SecondGene;
            std::string newGene2 = parent2FirstGene + parent1SecondGene;

            Chromosome* child1 = new Chromosome(newGene1);
            Chromosome* child2 = new Chromosome(newGene2);

            children.push_back(child1);
            children.push_back(child2);

            std::cout << "SinglepointCrossover: From parents : " << firstParent->getSequence() << " and  " << secondParent->getSequence() << std::endl;
            std::cout << "     First child = " << newGene1 << " (" << parent1FirstGene << ") and "
                      << " (" << parent2SecondGene << ")" << std::endl;
            std::cout << "     Second child = " << newGene2 << " (" << parent2FirstGene << ") and "
                      << " (" << parent1SecondGene << ")" << std::endl;
        }
    }

    for (Chromosome* parent : parents->getChromosomes())
        children.push_back(parent);

    parents->setChromosomes(children);
}