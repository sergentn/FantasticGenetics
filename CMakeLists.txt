cmake_minimum_required(VERSION 3.10)
set(CMAKE_BUILD_TYPE Debug)
project(FantasticGenetics)
add_executable(FantasticGenetics 
  main.cpp
  src/Chromosome.cpp
  src/ChromosomeFactory.cpp
  src/Population.cpp
  src/CrossoverOperator.cpp
  src/FitnessFunction.cpp
  src/GAEngine.cpp
  src/MaximizeOnesFitnessFunction.cpp
  src/SinglepointCrossover.cpp
  src/MutationOperator.cpp
  src/SelectionOperator.cpp
  src/ThresholdSelection.cpp
  src/BestOfSelection.cpp
)
target_include_directories(FantasticGenetics
  PRIVATE
  headers/
  lib/
)