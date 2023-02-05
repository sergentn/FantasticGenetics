#include <string>

#include "Chromosome.hpp"

Chromosome::Chromosome() {
    this->sequence = "Not initialized";
}

Chromosome::Chromosome(std::string sequence) {
    this->sequence = sequence;
}

std::string Chromosome::getSequence() {
    return this->sequence;
}

void Chromosome::setSequence(std::string newSequence) {
    this->sequence = newSequence;
}