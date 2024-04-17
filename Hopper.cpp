//
// Created by jrush_000 on 15/04/2024.
//

#include "Hopper.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Hopper::move() {
    srand(time(nullptr));   // Generate seed for rand
    const pair<int, int> current = position;    // log current position

    while (current == position) {   // Loop until Hopper has moved
        switch (direction) {    // Check Hopper direction
            case North: {
                if (isWayBlocked()) {
                    switch (rand() % 3 + 1) {   // Pick a random direction
                        default: { direction = East; }
                        case 2: { direction = South; }
                        case 3: { direction = West; }
                    }
                } else {
                    if(position.second + hopLength > 9) {
                        position.second = 9;
                    } else {
                        position.second += hopLength; // Move North
                    }
                }
            } break;
            case East: {
                if (isWayBlocked()) {
                    switch (rand() % 3 + 1) {   // Pick a random direction
                        default: {direction = North;}
                        case 2: {direction = South;}
                        case 3: {direction = West;}
                    }
                } else {
                    if(position.first + hopLength > 9) {
                        position.first = 9;
                    } else {
                        position.first += hopLength; // Move East
                    }
                }
            } break;
            case South: {
                if (isWayBlocked()) {
                    switch (rand() % 3 + 1) {   // Pick a random direction
                        default: {direction = North;}
                        case 2: {direction = East;}
                        case 3: {direction = West;}
                    }
                } else {
                    if(position.second - hopLength < 0) {
                        position.second = 0;
                    } else {
                        position.second -= hopLength; // Move South
                    }
                }
            } break;
            case West: {
                if (isWayBlocked()) {
                    switch (rand() % 3 + 1) {   // Pick a random direction
                        default: {direction = North;}
                        case 2: {direction = East;}
                        case 3: {direction = South;}
                    }
                } else {
                    if(position.first - hopLength < 0) {
                        position.first = 0;
                    } else {
                        position.first -= hopLength; // Move West
                    }
                }
            } break;
        }
    }
    path.push_back(position);
}

Hopper::~Hopper() = default;
