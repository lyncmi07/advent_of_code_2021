//
// Created by lynchm on 10/12/2021.
//

#include <iostream>

#include <string>
#include <cstring>

static const char* includeAll{
#include "aoc10_input.h"
#include "aoc10_tiny_test.h"
#include "aoc10test.h"
};

#define INPUT_FILE "aoc10_input.h"

template<int Value>
struct assertZero;

template<>
struct assertZero<0>
{

};

template<int InputLength>
consteval int getErrorInputPoints(const char* input)
{
    char stack[InputLength + 1];
    int stackCounter = 0;

    int errorCount = 0;
    bool lineErrorFound = false;

    for (int i = 0; i < InputLength; i++)
    {
        if (input[i] != '\n' && lineErrorFound)
        {
            continue;
        }

        switch (input[i])
        {
            case '(': stack[stackCounter++] = ')'; break;
            case '[': stack[stackCounter++] = ']'; break;
            case '<': stack[stackCounter++] = '>'; break;
            case '{': stack[stackCounter++] = '}'; break;
            case ')':
                if (stack[--stackCounter] != ')')
                {
                    errorCount += 3;
                    lineErrorFound = true;
                }
                break;
            case ']':
                if (stack[--stackCounter] != ']')
                {
                    errorCount += 57;
                    lineErrorFound = true;
                }
                break;
            case '>':
                if (stack[--stackCounter] != '>')
                {
                    errorCount += 25137;
                    lineErrorFound = true;
                }
                break;
            case '}':
                if (stack[--stackCounter] != '}')
                {
                    errorCount += 1197;
                    lineErrorFound = true;
                }
                break;
            case '\n':
                // start next line
                stackCounter = 0;
                lineErrorFound = false;
                break;
            default:
                // Skip character
                break;
        }
    }

    return errorCount;
}

int main()
{
    std::cout << "AoC 10 Compile Time" << std::endl;

    constexpr char value[] =
#include INPUT_FILE
        ;
    constexpr int valueSize = sizeof(value);

    std::cout << value << std::endl;

    constexpr int inputError = getErrorInputPoints<valueSize>(value);

    assertZero<inputError> assertion;
}