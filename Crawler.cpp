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
        int random = rand() % 3 + 1;
        // cout << random << ends;
        switch (direction) {    // Check Crawler direction
            case North: {
                // cout << ", North" << endl;
                if (isWayBlocked()) {
                    switch (random) {   // Pick a random direction
                        default: { direction = East; } break;
                        case 2: { direction = South; } break;
                        case 3: { direction = West; } break;
                    }
                } else {
                    position.second++; // Move North
                }
            } break;
            case East: {
                // cout << ", East" << endl;
                if (isWayBlocked()) {
                    switch (random) {   // Pick a random direction
                        default: {direction = North;} break;
                        case 2: {direction = South;} break;
                        case 3: {direction = West;} break;
                    }
                } else {
                    position.first++;   // Move East
                }
            } break;
            case South: {
                // cout << ", South" << endl;
                if (isWayBlocked()) {
                    switch (random) {   // Pick a random direction
                        default: {direction = North;} break;
                        case 2: {direction = East;} break;
                        case 3: {direction = West;} break;
                    }
                } else {
                    position.second--;  // Move South
                }
            } break;
            case West: {
                // cout << ", West" << endl;
                if (isWayBlocked()) {
                    switch (random) {   // Pick a random direction
                        default: {direction = North;} break;
                        case 2: {direction = East;} break;
                        case 3: {direction = South;} break;
                    }
                } else {
                    position.first--;   // Move West
                }
            } break;
        }
    }
    path.push_back(position);
}

void Crawler::print() {
        string str_direction;
        string str_alive;
        switch (direction) {
            case North: {str_direction = "North";}
            break;
            case East: {str_direction = "East";}
            break;
            case South: {str_direction = "South";}
            break;
            case West: {str_direction = "West";}
        }
        if(alive) {
            str_alive = "Alive";
        } else {
            str_alive = "Dead";
        }
        cout << id << " "
        << class_name() << " ("
        << position.first << ", "
        << position.second << ") "
        << size << " "
        << str_direction
        << " " << str_alive << endl;
}

Crawler::~Crawler() = default;

