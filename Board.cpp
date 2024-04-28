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
    cout << "Moving bugs..." << endl;
    for (Bug* bug : bug_vector) {
        if(bug->isAlive()) {    // If the bug is alive
            // cout << "Moving bug..." << endl;
            grid[bug->getPosition().first][bug->getPosition().second].remove(bug);   // Remove bug's current position on the grid
            bug->move();    // Move the bug
            grid[bug->getPosition().first][bug->getPosition().second].push_back(bug);   // Add bug's new position to the grid
        }
    }
    cout << endl << "Before fights:" << endl;
    displayAllCells();
    cout << endl;
    checkForFights();   // Fight check
    // cout << endl << "After fights:" << endl;
    // displayAllCells();
}

void Board::displayBugHistory() {
    for (Bug* bug : bug_vector) { bug->printHistory(); } // Print each Bug's history from the vector
}

void Board::writeBugHistory(const string &filename) {
    ofstream fout(filename);
    if (fout) {
        for (Bug* bug : bug_vector) {   // Write each bug's history to file
            bug->writeHistoryToFile(fout);
        }
        cout << "Bug history written to file " << filename << endl;
    } else {
        cout << "Failed to write to file." << endl;
    }
}

void Board::displayAllCells() const{
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            const list<Bug*>& bugList = grid[i][j];
            cout << "(" << i << "," << j << "): ";
            if(bugList.empty()) {   // If there are no bugs
                cout << "empty" << endl;
            } else {
                for (Bug* bug : bugList) {  // Go through all bugs in the list
                    if(bugList.front() != bug) {
                        cout << ", ";    // Display comma after first Bug
                    }
                    cout << bug->class_name() << " " << bug->getId();   // Display the bug's name and class
                }
                cout << endl;
            }
        }
    }
}

void Board::checkForFights() {
    for (vector<list<Bug*>>& gridX : grid) {
        for (list<Bug*>& bugList : gridX) {
            while (bugList.size() > 1) {    // Loop until only one bug is left in the cell
                // Get and remove the first two bugs from the list
                Bug* bug1 = bugList.front();
                bugList.pop_front();
                Bug* bug2 = bugList.front();
                bugList.pop_front();

                bug1->fightBug(bug2);   // Get bugs to fight

                if (bug1->isAlive()) {  // If bug1 is alive
                    bugList.push_front(bug1);   // Push bug1 back to front of list
                } else {    // bug2 is alive
                    bugList.push_front(bug2);   // Push bug2 back to front of list
                }
            }
        }
    }
}


