#ifndef MUTATIONOPERATOR_HPP
#define MUTATIONOPERATOR_HPP

#include "Chromosome.hpp"

#include <vector>
#include "Population.hpp"

class MutationOperator {
public:
    virtual void mutatePopulaton(Population* solutions, int mutationChancePercent);

protected:
    void singleBitMutation(Chromosome* chromosome);
};

#endif