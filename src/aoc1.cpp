//
// Created by lynchm on 01/12/2021.
//

#include <iostream>
#include <fstream>

#include "SlidingTotalWindow.h"

int main() {
    std::cout << "AOC1" << std::endl;


    std::ifstream measureFile("resources/aoc1.txt");
//    std::ifstream measureFile("resources/aoc1_test.txt");

    int noOfIncreases = 0;

    bool previousSet = false;
    int previousWindowMeasure;
    int currentMeasure;

    SlidingTotalWindow window(3);

    while (measureFile >> currentMeasure)
    {
        std::cout << "(" << currentMeasure << ") ";

        window.push(currentMeasure);

        if (window.ready() && !previousSet)
        {
            std::cout << window.getTotal() << " ";
            previousWindowMeasure = window.getTotal();
            previousSet = true;
            std::cout << "Setting previous" << std::endl;
            continue;
        }
        else if (window.ready())
        {
            std::cout << window.getTotal() << " ";
            if (previousWindowMeasure < window.getTotal()) {
                std::cout << " (increased)" << std::endl;
                noOfIncreases++;
            }
            else if (previousWindowMeasure > window.getTotal())
            {
                std::cout << "(decreased)" << std::endl;
            }
            else
            {
                std::cout << "(no change)" << std::endl;
            }

            previousWindowMeasure = window.getTotal();
        }
        else
        {
            std::cout << "Window not ready" << std::endl;
        }
    }

    std::cout << "Number of increases: " << noOfIncreases << std::endl;

    return 0;
}
