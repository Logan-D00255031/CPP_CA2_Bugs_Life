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

    ~Board() = default;
};


#endif //BOARD_H
