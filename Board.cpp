//
// Created by jrush_000 on 26/04/2024.
//

#include "Board.h"

#include <fstream>

#include "Crawler.h"
#include "Hopper.h"

void Board::initialise(const string& file_name) {
    ifstream fin(file_name);
    if(fin) {
        cout << "Accessing file..." << endl;
        string line;
        while(!fin.eof()) {
            getline(fin, line, ';');    // read until it reaches a ';'
            string bug_type = line;

            getline(fin, line, ';');
            const int bug_id = stoi(line);

            getline(fin, line, ';');
            const int x = stoi(line);

            getline(fin, line, ';');
            const int y = stoi(line);

            getline(fin, line, ';');
            Direction bug_direction;
            switch(stoi(line)) {
                default: {bug_direction = North;}
                break;
                case 2: {bug_direction = East;}
                break;
                case 3: {bug_direction = South;}
                break;
                case 4: {bug_direction = West;}
            }

            getline(fin, line, ';');
            const int bug_size = stoi(line);

            getline(fin, line);
            if(bug_type == "H") {
                const int bug_hop = stoi(line);
                bug_vector.push_back(new Hopper(bug_id, x, y, bug_direction, bug_size, bug_hop));
            } else {
                bug_vector.push_back(new Crawler(bug_id, x, y, bug_direction, bug_size));
            }
        }
        fin.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}

void Board::displayBugs() {
    for(Bug* bug: bug_vector) { bug->print(); } // Print each Bug from the vector
}

void Board::findBug(const int id) {
    bool foundBug = false;
    for (Bug* bug : bug_vector) {
        if(bug->isId(id)) {
            cout << "Bug Found!" << endl;
            bug->print();
            foundBug = true;
        }
    }
    if (!foundBug) {
        cout << "Bug " << id << " not found" << endl;
    }
}

void Board::tap() {
    for (Bug* bug : bug_vector) {
        if(bug->isAlive()) {
            cout << "Moving bug..." << endl;
            bug->move();
        }
    }
}


