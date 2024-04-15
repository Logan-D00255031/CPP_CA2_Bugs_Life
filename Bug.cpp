//
// Created by jrush_000 on 15/04/2024.
//

#include "Bug.h"

bool Bug::isWayBlocked() {
    if(direction == North && position.second == 9) {
        return true;
    }
    if (direction == East && position.first == 9) {
        return true;
    }
    if (direction == South && position.second == 0) {
        return true;
    }
    if (direction == West && position.first == 0) {
        return true;
    }
    return false;
}

Bug::~Bug() = default;

