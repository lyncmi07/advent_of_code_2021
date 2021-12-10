//
// Created by Michael Lynch on 03/12/2021.
//


#include <iostream>
#include <map>

#include <FileHandler.hpp>

int main()
{
    std::cout << "AOC3" << std::endl;

//    auto reportFile = aoc::getFile("resources/aoc3_test.txt");
    auto reportFile = aoc::getFile("resources/aoc3.txt");

    std::string reportLine;
    reportFile >> reportLine;

    unsigned int numberSize = reportLine.size();
    std::map<unsigned int, int> gammaCounters;

    int totalLines = 1;
    while (reportFile >> reportLine)
    {
        totalLines++;
        std::cout << reportLine << std::endl;
        for (unsigned int i = 0; i < reportLine.size(); i++)
        {
            // gammaCount[i] = reportLine
            switch (reportLine[i])
            {
                case '0':
                    gammaCounters[i]--;
                    break;
                case '1':
                    gammaCounters[i]++;
                    break;
                default:
                    throw std::runtime_error(&"Unexpected character: " [ reportLine[i]]);
            }
        }
    }

    int gammaRate = 0;
    int epsilonMask = 0;
    for (auto [index, count]: gammaCounters)
    {
        epsilonMask |= 1 << index;
        if (count > 0)
        {
            gammaRate |= 1 << (numberSize - index - 1);
        }
        else if (count == 0)
        {
            std::cout << "WARN: ambigious reading" << std::endl;
        }
    }

    int epsilon = (epsilonMask & ~gammaRate);

    std::cout << "Mask: " << epsilonMask << std::endl;
    std::cout << "Gamma: " << gammaRate << std::endl;
    std::cout << "Epsilon: " << epsilon << std::endl;

    std::cout << "Power usage: " << epsilon * gammaRate << std::endl;
}