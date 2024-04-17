//
// Created by jrush_000 on 15/04/2024.
//
#ifndef HOPPER_H
#define HOPPER_H

#include "Bug.h"

class Hopper : public Bug {
private:
    int hopLength;
public:
    Hopper(const int id, const int x, const int y, const Direction direction, const int size, const int hopLength) {
        this->id = id;
        this->position.first = x;
        this->position.second = y;
        this->direction = direction;
        this->size = size;
        this->hopLength = hopLength;
        alive = true;
        path.push_back(position);
    }

    void move() override;

    ~Hopper() override;
};



#endif //HOPPER_H
