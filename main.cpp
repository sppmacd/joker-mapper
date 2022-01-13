/*! \file main.cpp
 *
 * \brief Kod programu testującego klasę Punkt2 i Polygon
 *
 * Plik zawiera funkcję main(),
 * w której wykonano kilka podstawowych testów
 * dotyczących klasy Punkt2 oraz Polygon.
 *
 * \author Maciej Zygmanowski
 * \date 2022-01-13
 * \version 1.0.0
 */

#include "Polygon.h"
#include "Punkt2.h"

#include <iostream>

int main() {
    // Punkt2 - przeciążanie operatorów
    Punkt2 p1{10, 10};
    Punkt2 p2{50, 14};

    Punkt2 add = p1 + p2;
    Punkt2 subtract = p1 - p2;
    double dot_product = p1 * p2;
    std::cout << "Add result: " << add.getX() << "," << add.getY() << std::endl;
    std::cout << "Subtract result: " << subtract.getX() << "," << subtract.getY() << std::endl;
    std::cout << "Dot product: " << dot_product << std::endl;

    return 0;
}
