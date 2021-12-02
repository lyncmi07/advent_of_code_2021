//
// Created by lynchm on 02/12/2021.
//

#include <iostream>
#include <fstream>

int main()
{
    std::cout << "AOC2" << std::endl;

    std::ifstream measureFile("resources/aoc2.txt");
//    std::ifstream measureFile("resources/aoc2_test.txt");

    int depth = 0;
    int x = 0;

    std::string direction;
    int velocity;

    while(measureFile >> direction >> velocity)
    {
        std::cout << direction << " at v=" << velocity << std::endl;

        if (direction == "forward")
        {
            x += velocity;
        }
        else if (direction == "down")
        {
            depth += velocity;
        }
        else if (direction == "up")
        {
            depth -= velocity;
        }
        else
        {
            throw std::runtime_error("Unknown direction " + direction);
        }
    }

    std::cout << "Movement total: " << depth * x << std::endl;
}