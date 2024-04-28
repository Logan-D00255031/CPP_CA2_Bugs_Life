//
// Created by jrush_000 on 15/04/2024.
//

#include "Bug.h"

#include <fstream>

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
    cout << id << " " << class_name() << " Path: ";  // Display id, bug type, and begin path history
    for (pair<int, int> pair : path) {
        if (path.front() != pair) {
            cout << ",";    // Add comma after first position
        }
        cout << "(" << pair.first << "," << pair.second << ")";     // Display x and y of position
    }
    // Display life status
    if(alive) { cout << " Alive!" << endl; }
    else { cout << " Eaten by " << killerId << endl;}   // Give the id of the bug that ate it if dead
}

const int& Bug::getId() const {
    return id;
}

void Bug::writeHistoryToFile(ofstream& fout) {
    if (fout) {
        fout << id << " " << class_name() << " Path: ";
        for (pair<int, int> pair : path) {
            if (path.front() != pair) {
                fout << ",";
            }
            fout << "(" << pair.first << "," << pair.second << ")";
        }
        if(alive) { fout << " Alive!" << endl; }
        else { fout << " Eaten by " << killerId << endl;}
    }
}

Bug::~Bug() = default;

