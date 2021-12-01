//
// Created by lynchm on 01/12/2021.
//

#include "SlidingTotalWindow.h"

SlidingTotalWindow::SlidingTotalWindow(int size)
    : size_{size}
{

}

bool SlidingTotalWindow::ready() {
    return elements_.size() == size_;
}

void SlidingTotalWindow::push(int newElement)
{
    total_ += newElement;
    elements_.push(newElement);
    if (elements_.size() > size_)
    {
        auto poppedElement = elements_.front();
        total_ -= poppedElement;
        elements_.pop();
    }
}
