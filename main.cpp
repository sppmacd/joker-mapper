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
    // Nie ma ani jednego wywołania konstruktora Punkt2(double, double). Wszystkie to
    // są Punkt2(std::initializer_list<double>).
    std::initializer_list<Punkt2> punkty1 { Punkt2 { 2, 4 }, Punkt2 { 4, 7 }, Punkt2 { 5, 2 }, Punkt2 { 6, 3 } };
    std::vector<Punkt2> punkty2 { Punkt2 { 2, 4 }, Punkt2 { 4, 7 }, Punkt2 { 5, 2 }, Punkt2 { 6, 3 } };
    std::initializer_list<Punkt2> punkty3 { { 4.0, 7.0 }, { 40.0, 70.0 }, { 400.0, 700.0 } };
    std::vector<Punkt2> punkty4 { { 4.0, 7.0 }, { 40.0, 70.0 }, { 400.0, 700.0 } };

    // test jawny initializer_list
    {
        Polygon pol1 { punkty1 };
        std::cout << pol1 << std::endl;
    }

    // test jawny Punkt2
    {
        // tylko tutaj wywołuje się Punkt2(double, double)
        Polygon pol1 { Punkt2(0, 0), Punkt2(0, 1), Punkt2(0, 5), Punkt2(6, 0) };
        std::cout << pol1 << std::endl;
    }

    // test tylko initializer_list
    {
        Polygon pol1 { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } };
        std::cout << pol1 << std::endl;
    }

    // test initializer list punktów
    {
        Punkt2 p1 { 2, 5 };
        Punkt2 p2 { 3, 4 };
        Punkt2 p3 { 4, 3 };
        Punkt2 p4 { 5, 2 };
        Polygon pol1 { p1, p2, p3, p4 };
        std::cout << pol1 << std::endl;
    }

    // test mieszany
    {
        Punkt2 p2 { 3, 4 };
        Punkt2 p4 { 5, 2 };
        Polygon pol1 { { 10, 10 }, p2, { 0, 0 }, p4 };
        std::cout << pol1 << std::endl;
    }
    return 0;
}
