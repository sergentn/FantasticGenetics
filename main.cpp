#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Chromosome.hpp"
#include "ChromosomeFactory.hpp"
#include "GAEngine.hpp"

#include "Enums.hpp"
#include "ini_parser.hpp"

// TODO :
//        Classe Population qui contient tous les individus
//        SinglePoint CrossOver : à partir de 2 séquences, retourne 2 séquences + milieu choisi aléatoirement
//        Possibilité de faire tourner l'algorithme tant qu'on n'a pas trouvé un certain nombre de solutions au dessus du seuil
//        Sortie des résultats sous forme de fichier ?

void printUsage()
{
    std::cout << "FantasticGenetics. Usage: ./FantasticGenetics <params.ini>" << std::endl;
    exit(0);
}

int main(int argc, char* argv[])
{
    srand((unsigned int)time(NULL)); // set the seed of the rand function

    /* Args parsing : TODO */
    std::cout << "argc == " << argc << '\n';
    for (int ndx {}; ndx != argc; ++ndx) {
        std::cout << "argv[" << ndx << "] == " << std::quoted(argv[ndx]) << '\n';
    }
    std::cout << "argv[" << argc << "] == " << static_cast<void*>(argv[argc]) << '\n';
    /*...*/
    // return argc == 3 ? EXIT_SUCCESS : EXIT_FAILURE; // optional return value

    // We need only one arg: the parameters file
    if (argc != 2)
        printUsage();

    /* Read from the INI file */
    mINI::INIFile file(argv[1]);
    mINI::INIStructure ini;
    file.read(ini);

    // General settings
    int iterationsNb = stoi(ini.get("General").get("iterations_number"));
    int chromosomesLength = stoi(ini.get("General").get("chromosomes_length"));
    int initialPopSize = stoi(ini.get("General").get("initial_population_size"));

    // Fitness function
    EFitnessFunction fitnessFunction = EFitnessFunction::MAXIMIZE_ONES;
    std::string fitnessFunctionStr = ini.get("Selection").get("fitness_function");
    if (fitnessFunctionStr == "maximize_ones")
        fitnessFunction = EFitnessFunction::MAXIMIZE_ONES;

    // Selection method
    ESelectionMethod selectionMethod = ESelectionMethod::THRESHOLD;
    std::string selectionMethodStr = ini.get("Selection").get("selection_method");
    std::cout << "SELECTION METHODSTR : " << selectionMethodStr << std::endl;
    if (selectionMethodStr == "threshold")
        selectionMethod = ESelectionMethod::THRESHOLD;
    if (selectionMethodStr == "bestof")
        selectionMethod = ESelectionMethod::BESTOF;

    double fitnessThreshold = stod(ini.get("Selection").get("fitness_threshold"));
    int bestOfNumber = stoi(ini.get("Selection").get("bestof_number"));

    // Crossover operator
    ECrossoverOperator crossoverOperator = ECrossoverOperator::SINGLEPOINT;
    std::string crossoverOperatorStr = ini.get("Crossover").get("crossover_operator");
    if (crossoverOperatorStr == "singlepoint")
        crossoverOperator = ECrossoverOperator::SINGLEPOINT;

    // Mutations
    int mutationChancePercent = stoi(ini.get("Mutations").get("mutation_chance_percent"));

    // Start the computation
    auto startTime = std::chrono::high_resolution_clock::now();

    GAEngine* simulation = new GAEngine(iterationsNb, chromosomesLength, initialPopSize, fitnessThreshold, bestOfNumber, mutationChancePercent, fitnessFunction, crossoverOperator, selectionMethod);

    simulation->process();
    simulation->displayFinalRanking();

    // Computation is finished
    auto endTime = std::chrono::high_resolution_clock::now();
    auto totalTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    std::cout << "--------------------" << std::endl;
    std::cout << "Simulation complete in " << totalTime.count() << " ms." << std::endl;

    return 0;
}