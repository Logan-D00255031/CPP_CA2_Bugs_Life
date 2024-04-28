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

    bool run = true;
    Board board{};

    while (run) {
        cout << "1. Initialize Bug Board (load data from file)" << endl
        << "2. Display all Bugs" << endl
        << "3. Find a Bug (given an id)" << endl
        << "4. Tap the Bug Board (causes move all, then fight/eat)" << endl
        << "5. Display Life History of all Bugs (path taken)" << endl
        << "6. Display all Cells listing their Bugs" << endl
        << "7. Run simulation (generates a Tap every second)" << endl
        << "8. Exit (write Life History of all Bugs to file)" << endl
        << "Select a menu item: " << ends;
        int menuItem;
        cin >> menuItem;
        switch (menuItem) {
            default: { cout << "Invalid Command."; }
            break;
            case 1: {
                string filename;
                cout << "File Name: " << ends;
                cin >> filename;
                board.initialise(filename);
            }
            break;
            case 2: {
                cout << endl;
                board.displayBugs();
            }
            break;
            case 3: {
                cout << endl << "Enter the Bug id: " << ends;
                int id;
                cin >> id;
                cout << endl;
                board.findBug(id);
            }
            break;
            case 4: { board.tap(); }
            break;
            case 5: {
                cout << endl;
                board.displayBugHistory();
            }
            break;
            case 6: {
                cout << endl;
                board.displayAllCells();
            }
            break;
            case 7: { runSimulation(board); }
            break;
            case 8: {
                cout << "Writing Bug history to file..." << endl;
                board.writeBugHistory("bugs_life_history_date_time.out");
                cout << "Goodbye!" << endl;
                run = false;
            }
            break;
        }
        cout << endl;
    }

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
    // cout << endl << aliveBugs << endl;
    cout << endl;
    board.writeBugHistory("bugs_life_history_date_time.out");   // Write bug history
}

