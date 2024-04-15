//
// Created by jrush_000 on 15/04/2024.
//

#ifndef CRAWLER_H
#define CRAWLER_H
#include "Bug.h"

class Crawler : public Bug {
public:
    Crawler(const int id, const int x, const int y, const Direction direction, const int size) {
        this->id = id;
        this->position.first = x;
        this->position.second = y;
        this->direction = direction;
        this->size = size;
        alive = true;
        path.push_back(position);
    }

    void move() override;

    ~Crawler() override;
};

#endif //CRAWLER_H
