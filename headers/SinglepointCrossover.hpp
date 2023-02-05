#ifndef SINGLEPOINTCROSSOVER_HPP
#define SINGLEPOINTCROSSOVER_HPP

#include "CrossoverOperator.hpp"

class SinglepointCrossover : public CrossoverOperator {
public:
    void doCrossover(Population* parents) override;

protected:
};

#endif