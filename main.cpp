#include <iostream>
#include "Crawler.h"
#include "Hopper.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Direction test = North;

    Crawler crawler(100, 0, 0, North, 10);
    Hopper hopper(100, 9, 0, West, 10, 2);


    crawler.move();
    hopper.move();

    return 0;
}
