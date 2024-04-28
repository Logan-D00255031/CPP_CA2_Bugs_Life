//
// Created by jrush_000 on 28/04/2024.
//

#include "Skitterer.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Skitterer::move() {
    srand(time(nullptr));   // Generate seed for rand
    const pair<int, int> current = position;    // log current position

    while (current == position) {   // Loop until Skitterer has moved
        const int random = rand() % 3 + 1;
        // cout << random << ends;
        switch (direction) {    // Check Skitterer direction
            case North: {
                // cout << ", North" << endl;
                if (isWayBlocked()) {
                    switch (random) {   // Pick a random direction
                        default: { direction = East; } break;
                        case 2: { direction = South; } break;
                        case 3: { direction = West; } break;
                    }
                } else {
                    // Moving North
                    if(position.second + stepLength > 9) {
                        position.second = 9;
                    } else {
                        position.second += stepLength; // Move North
                    }

                    if (skitter_direction == Left) {    // If moving Left
                        if(position.first - stepLength < 0) {
                            position.first = 0;
                        } else {
                            position.first -= stepLength; // Move West
                        }
                    } else {    // Moving Right
                        if(position.first + stepLength > 9) {
                            position.first = 9;
                        } else {
                            position.first += stepLength; // Move East
                        }
                    }
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
                    // Moving East
                    if(position.first + stepLength > 9) {
                        position.first = 9;
                    } else {
                        position.first += stepLength; // Move East
                    }

                    if (skitter_direction == Left) {    // If moving Left
                        if(position.second + stepLength > 9) {
                            position.second = 9;
                        } else {
                            position.second += stepLength; // Move North
                        }
                    } else {    // Moving Right
                        if(position.second - stepLength < 0) {
                            position.second = 0;
                        } else {
                            position.second -= stepLength; // Move South
                        }
                    }
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
                    // Moving South
                    if(position.second - stepLength < 0) {
                        position.second = 0;
                    } else {
                        position.second -= stepLength; // Move South
                    }

                    if (skitter_direction == Left) {    // If moving Left
                        if(position.first + stepLength > 9) {
                            position.first = 9;
                        } else {
                            position.first += stepLength; // Move East
                        }
                    } else {    // Moving Right
                        if(position.first - stepLength < 0) {
                            position.first = 0;
                        } else {
                            position.first -= stepLength; // Move West
                        }
                    }
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
                    // Moving West
                    if(position.first - stepLength < 0) {
                        position.first = 0;
                    } else {
                        position.first -= stepLength; // Move West
                    }

                    if (skitter_direction == Left) {    // If moving Left
                        if(position.second - stepLength < 0) {
                            position.second = 0;
                        } else {
                            position.second -= stepLength; // Move South
                        }
                    } else {    // Moving Right
                        if(position.second + stepLength > 9) {
                            position.second = 9;
                        } else {
                            position.second += stepLength; // Move North
                        }
                    }
                }
            } break;
        }
    }
    path.push_back(position);   // Add postion to history
    // Change direction for next move
    if (skitter_direction == Left) {
        skitter_direction = Right;
    } else {
        skitter_direction = Left;
    }
}

void Skitterer::print() {
    string str_direction;
    string str_alive;
    switch (direction) {    // Convert Direction to string
        case North: {str_direction = "North";}
        break;
        case East: {str_direction = "East";}
        break;
        case South: {str_direction = "South";}
        break;
        case West: {str_direction = "West";}
    }
    if(alive) { // Convert boolean to string
        str_alive = "Alive";
    } else {
        str_alive = "Dead";
    }
    // Print to console
    cout << id << " "
    << class_name() << " ("
    << position.first << ", "
    << position.second << ") "
    << size << " "
    << str_direction << " "
    << stepLength << " "
    << str_alive << endl;
}

Skitterer::~Skitterer() = default;

