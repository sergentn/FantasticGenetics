#ifndef CHROMOSOME_HPP
#define CHROMOSOME_HPP

#include <string>

class Chromosome {
public:
    Chromosome();
    Chromosome(std::string sequence);
    std::string getSequence();
    void setSequence(std::string newSequence);

protected:
    std::string sequence;
};

#endif