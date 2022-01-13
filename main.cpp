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

#include <initializer_list>
#include <iostream>

int main() {
    // operator przypisania
    Polygon p1;
    Polygon p2 { { 0, 0 }, { 0, 10 }, { 10, 10 }, { 10, 0 } };
    p1 = p2;
    std::cout << p1 << "; " << p2 << std::endl;
    p1 = Polygon { { 5, 5 }, { 3, 3 }, { 2, 2 } };
    std::cout << p1 << "; " << p2 << std::endl;
    p1 = Polygon { { 1, 1 }, { 2, 1 }, { 1, 3 }, { 4, 1 }, { 1, 5 } };
    std::cout << p1 << "; " << p2 << std::endl;

    // nic nie powinno się stać
    std::cout << "p1 = p1 za chwilę..." << std::endl;
    p1 = p1;
    std::cout << "po p1 = p1..." << std::endl;

    // operator[]
    std::cout << p1[0] << "," << p1[3] << std::endl;
    return 0;
}
