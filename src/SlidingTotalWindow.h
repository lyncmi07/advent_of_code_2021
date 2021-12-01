//
// Created by lynchm on 01/12/2021.
//


#pragma once

#include <queue>

class SlidingTotalWindow {
public:
    SlidingTotalWindow(int size);

    void push(int newElement);

    auto getTotal() const { return total_; }
    bool ready();
private:
    std::queue<int> elements_;
    int total_{0};
    int size_;
};


