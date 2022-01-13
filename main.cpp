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

#include "Matrix.h"
#include "Polygon.h"
#include "Punkt2.h"

#include <initializer_list>
#include <iostream>

Polygon f(Polygon arg)
{
    return arg;
}

int main() {
    std::cout << "-----------1----------" << std::endl;
    Polygon p1 = {{1.0, 2.0}};
    std::cout << "-----------2----------" << std::endl;
	Polygon p2 = p1;
    std::cout << "-----------3----------" << std::endl;
	Polygon p5 = f({{10, 20}});
    std::cout << "-----------4----------" << std::endl;
    p2 = p1;
    std::cout << "-----------5----------" << std::endl;
    p2 = std::move(p1);
    std::cout << "----------------------" << std::endl;

    // MATRIX
    Matrix mat;
    std::cout << mat << std::endl;

    Matrix mat2{4,4};
    std::cout << mat2 << std::endl;
    mat2[0][0] = 1;
    mat2(1,1) = 1;
    mat2[2][2] = 1;
    mat2(3,3) = 1;
    std::cout << mat2(0,0) << "," << mat2(2,2) << std::endl; // 1,1
    std::cout << mat2 << std::endl; // macierz jednostkowa
    return 0;
}

/*
WYNIK:

(g++ -std=c++20 -fsanitize=undefined,address -g -o klasy *.cpp && ./klasy)

-----------1----------
Polygon::Polygon(std::initializer_list<Punkt2>)
-----------2----------
Polygon::Polygon(const Polygon&)
-----------3----------
Polygon::Polygon(std::initializer_list<Punkt2>)
Polygon::Polygon(Polygon&&)
Polygon::~Polygon()
-----------4----------
Polygon& Polygon::operator=(const Polygon&)
-----------5----------
Polygon& Polygon::operator=(Polygon&&)
----------------------
*/
