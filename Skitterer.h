//
// Created by jrush_000 on 28/04/2024.
//

#ifndef SKITTERER_H
#define SKITTERER_H

#include "Bug.h"

enum Skitter_Direction {Left, Right};

class Skitterer : public Bug {
private:
    int stepLength;
    Skitter_Direction skitter_direction;
public:
    Skitterer(const int id, const int x, const int y, const Direction direction, const int size, const int stepLength) {
        this->id = id;
        this->position.first = x;
        this->position.second = y;
        this->direction = direction;
        this->size = size;
        this->stepLength = stepLength;
        alive = true;
        skitter_direction = Left;
        path.push_back(position);
    }

    void move() override;

    void print() override;

    string class_name() override {
        return "Skitterer";
    }

    ~Skitterer() override;
};



#endif //SKITTERER_H
