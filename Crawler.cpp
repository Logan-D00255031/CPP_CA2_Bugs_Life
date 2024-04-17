//
// Created by jrush_000 on 15/04/2024.
//

#include "Crawler.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void Crawler::move() {
    srand(time(nullptr));   // Generate seed for rand
    const pair<int, int> current = position;    // log current position

    while (current == position) {   // Loop until Crawler has moved
        switch (direction) {    // Check Crawler direction
            case North: {
                if (isWayBlocked()) {
                    switch (rand() % 3 + 1) {   // Pick a random direction
                        default: { direction = East; }
                        case 2: { direction = South; }
                        case 3: { direction = West; }
                    }
                } else {
                    position.second++; // Move North
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
                    position.first++;   // Move East
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
                    position.second--;  // Move South
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
                    position.first--;   // Move West
                }
            } break;
        }
    }
    path.push_back(position);
}

Crawler::~Crawler() = default;

