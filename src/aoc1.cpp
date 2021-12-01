//
// Created by lynchm on 01/12/2021.
//

#include <iostream>
#include <vector>
#include <fstream>

int main() {
    std::cout << "AOC1" << std::endl;


    std::ifstream measureFile("resources/aoc1.txt");

    int previousMeasure;
    measureFile >> previousMeasure;

    std::cout << "(" << previousMeasure << ") " << std::endl;
    int noOfIncreases = 0;

    int currentMeasure;

    while (measureFile >> currentMeasure)
    {
        std::cout << "(" << currentMeasure << ") ";
        if (previousMeasure < currentMeasure)
        {
            std::cout << "(increased)" << std::endl;
            noOfIncreases++;
        }
        else if (previousMeasure > currentMeasure)
        {
            std::cout << "(decreased)" << std::endl;
        }
        else
        {
            std::cout << "(no change)" << std::endl;
        }

        previousMeasure = currentMeasure;
    }

    std::cout << "Number of increases: " << noOfIncreases << std::endl;

    return 0;
}
