#include <windows.h>
#include "Crawler.h"
#include "Hopper.h"
#include "Board.h"

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void runSimulation(Board& board);

int main() {
    /*
    vector<Bug*> bug_vector;

    // bug_vector.push_back();

    ifstream fin("bugs.txt");
    if(fin) {
        cout << "Accessing file..." << endl;
        string line;
        while(!fin.eof()) {
            fin >> line;
            // cout << "Current Bug: " << line << endl;
            string::size_type start_pos;
            string::size_type end_pos = line.find(';');
            string bug_type = line.substr(0, end_pos);

            start_pos = end_pos + 1;
            end_pos = line.find(';', start_pos);
            int bug_id = stoi(line.substr(start_pos, end_pos - start_pos));

            start_pos = end_pos + 1;
            end_pos = line.find(';', start_pos);
            int x = stoi(line.substr(start_pos, end_pos - start_pos));

            start_pos = end_pos + 1;
            end_pos = line.find(';', start_pos);
            int y = stoi(line.substr(start_pos, end_pos - start_pos));

            start_pos = end_pos + 1;
            end_pos = line.find(';', start_pos);
            Direction bug_direction;
            switch(stoi(line.substr(start_pos, end_pos))) {
                default: {bug_direction = North;}
                break;
                case 2: {bug_direction = East;}
                break;
                case 3: {bug_direction = South;}
                break;
                case 4: {bug_direction = West;}
            }

            start_pos = end_pos + 1;
            end_pos = line.find(';', start_pos);
            int bug_size = stoi(line.substr(start_pos, end_pos - start_pos));
            int bug_hop;
            if(bug_type == "H") {
                start_pos = end_pos + 1;
                end_pos = line.find(';', start_pos);
                bug_hop = stoi(line.substr(start_pos, end_pos - start_pos));
            }
            /* cout << bug_type << " "
            << bug_id << " "
            << x << " "
            << y << " "
            << bug_direction + 1 << " "
            << bug_size << " " << endl;

            if(bug_type == "H") {
                // cout << bug_hop << " " << endl;
                bug_vector.push_back(new Hopper(bug_id, x, y, bug_direction, bug_size, bug_hop));
            } else {
                bug_vector.push_back(new Crawler(bug_id, x, y, bug_direction, bug_size));
            }
        }
        fin.close();
    } else {
        cout << "Unable to open file" << endl;
    }

    for(Bug* bug: bug_vector) {
        bug->print();
    }

    cout << endl << "Search for a Bug id: " << endl;
    int id;
    cin >> id;

    for (Bug* bug : bug_vector) {
        if(bug->isId(id)) {
            cout << "Bug Found!" << endl;
            bug->print();
        }
    }
    */

    Board board{};
    board.initialise("bugs.txt");
    // board.initialise("bugFightTest.txt");
    board.displayBugs();

    cout << endl << "Search for a Bug id: " << endl;
    int id;
    cin >> id;

    board.findBug(id);

    cout << endl;
    runSimulation(board);

    return 0;
}

void runSimulation(Board &board) {
    cout << "Running Simulation..." << endl;
    int count = 1;
    vector<Bug*>::size_type aliveBugs = board.aliveBugCount();  // Get amount of bugs alive
    while (aliveBugs > 1 && count < 100) { // If more than one bug is still alive and less than 100 taps have been completed
        cout << endl << "Tap " << count << ":" << endl << endl;
        board.tap();    // Tap the bug board
        cout << endl;
        board.displayBugs();    // Show status of all bugs
        aliveBugs = board.aliveBugCount();  // Check alive bugs remaining
        Sleep(1000);    // Wait one second
        count++;    // Increase the tap count
    }
    cout << endl;
    board.displayBugHistory();  // Display bug history
    cout << endl;
    board.writeBugHistory("bugs_life_history_date_time.out");   // Write bug history
}

