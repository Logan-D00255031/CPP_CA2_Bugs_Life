//
// Created by jrush_000 on 15/04/2024.
//

#include "Bug.h"

using namespace std;

bool Bug::isWayBlocked() const {
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

bool Bug::isId(const int id) const {
    if(this->id == id) { return true; }
    return false;
}

bool Bug::isAlive() const {
    return this->alive;
}

void Bug::printHistory() {
    cout << id << " " << class_name() << " Path:" << ends;
    for (pair<int, int> pair : path) {
        if (path.front() != pair) {
            cout << ",";
        }
        cout << "(" << pair.first << "," << pair.second << ")";
    }
    if(alive) { cout << " Alive!" << endl; }
    else { cout << " Eaten by " << endl;}    // Add the killer's id to this !!!
}

Bug::~Bug() = default;

