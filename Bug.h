//
// Created by jrush_000 on 15/04/2024.
//
#ifndef BUG_H
#define BUG_H

#include <list>
#include <iostream>
#include <utility>

using namespace::std;
enum Direction {North, East, South, West};

class Bug {
protected:
    int id;
    pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    list<pair<int, int>> path;
    int killerId;
public:
    virtual void move() =0;
    bool isWayBlocked() const;

    virtual ~Bug();

    virtual string class_name() =0;
    virtual void print() =0;
    void printHistory();
    void writeHistoryToFile(ofstream& fout);
    void fightBug(Bug* bug);
    void eat(int size);
    void eatenByBug(int id);

    const int& getId() const;
    const pair<int, int>& getPosition() const;
    bool isId(int id) const;
    bool isAlive() const;
};

#endif //BUG_H
