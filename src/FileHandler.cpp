//
// Created by Michael Lynch on 03/12/2021.
//

#include "FileHandler.hpp"

namespace aoc
{
    std::ifstream getFile(const std::string &fileName)
    {
        std::ifstream f(fileName);
        if (!f.is_open()) throw std::runtime_error("Could not open file: " + fileName);

        return f;
    }
}

