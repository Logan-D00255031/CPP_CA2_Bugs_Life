//
// Created by jrush_000 on 26/04/2024.
//

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <list>
#include <vector>

#include "Bug.h"

using namespace std;

class Board {
private:
    vector<Bug*> bug_vector;
    vector<vector<list<Bug*>>> grid;
public:
    Board() {
        grid = vector<vector<list<Bug*>>>(10, vector<list<Bug*>>(10));  // Set grid size
    }

    void initialise(const string& file_name);
    void displayBugs();
    void findBug(int id);
    void tap();
    void displayBugHistory();
    void writeBugHistory(const string& filename);
    void displayAllCells() const;
    void checkForFights();
    vector<Bug*>::size_type aliveBugCount() const;

    ~Board() {
        for (Bug* bug : bug_vector) {
            delete bug;
        }
    }
};


#endif //BOARD_H
