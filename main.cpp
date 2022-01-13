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
    // Polygon - konstruktor kopiujący

    // 1. Pusty - sprawdzanie czy się nie crashuje
    {
        Polygon p1;
        Polygon p2 { p1 };
        std::cout << "Ilość obiektów: " << Polygon::getObjectCount() << std::endl;
    }
    std::cout << "Ilość obiektów: " << Polygon::getObjectCount() << std::endl;

    // 2. Zapełniony
    {
        Polygon p1 { {
            Punkt2 { 0, 1 },
            Punkt2 { 0, 2 },
            Punkt2 { 0, 3 },
            Punkt2 { 0, 4 },
            Punkt2 { 0, 5 },
        } };
        Polygon p2 { p1 };
        std::cout << p2 << std::endl;
        std::cout << "Ilość obiektów: " << Polygon::getObjectCount() << std::endl;
    }
    std::cout << "Ilość obiektów: " << Polygon::getObjectCount() << std::endl;

    return 0;
}
