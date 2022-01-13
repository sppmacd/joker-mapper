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

Punkt2 f(Punkt2 arg)
{
    return arg;
}

int main() {
    std::cout << "-----------1----------" << std::endl;
    Punkt2 p1 = Punkt2(1.0, 2.0);
    std::cout << "-----------2----------" << std::endl;
	Punkt2 p2 = p1;
    std::cout << "-----------3----------" << std::endl;
	Punkt2 p3 = p1 + p2;
    std::cout << "-----------4----------" << std::endl;
	Punkt2 p4 = Punkt2(1000, 2000) + Punkt2(3000, 4000);
    std::cout << "-----------5----------" << std::endl;
	Punkt2 p5 = f(Punkt2(10, 20));
    std::cout << "-----------6----------" << std::endl;
	Punkt2 p6 = f(Punkt2(100, 200) + Punkt2(100, 200));
    std::cout << "----------------------" << std::endl;
    return 0;
}

/*
WYNIK:

(g++ -std=c++20 -fsanitize=undefined,address -g -o klasy *.cpp && ./klasy)

-----------1----------
Punkt2::Punkt2(double, double)
-----------2----------
Punkt2::Punkt2(const Punkt2&)
-----------3----------
Punkt2::Punkt2(std::initializer_list<double>)
-----------4----------
Punkt2::Punkt2(double, double)
Punkt2::Punkt2(double, double)
Punkt2::Punkt2(std::initializer_list<double>)
Punkt2::~Punkt2()
Punkt2::~Punkt2()
-----------5----------
Punkt2::Punkt2(double, double)
Punkt2::Punkt2(Punkt2&&)
Punkt2::~Punkt2()
-----------6----------
Punkt2::Punkt2(double, double)
Punkt2::Punkt2(double, double)
Punkt2::Punkt2(std::initializer_list<double>)
Punkt2::Punkt2(Punkt2&&)
Punkt2::~Punkt2()
Punkt2::~Punkt2()
Punkt2::~Punkt2()
----------------------

1. wywołany tylko (double, double) bo inicjalizacja z rvalue
2. Nastąpiła kopia
3. został wywołany konstruktor std::initializer_list (poprzez operator+) bo inicjalizacja z rvalue
4. utworzone dwa obiekty, poza tym std::initializer_list (poprzez operator+) bo inicjalizacja z rvalue
5. wywołany konstruktor przenoszący z funkcji - pominięcie kopiowania!!!
6. utworzenie dwóch obiektów, inicjalizacja argumentu z rvalue, następnie skopiowanie do zmiennej z pominięciem kopiowania!!!

Konstruktor przesuwający informuje kompilator, że ta klasa może być "przesuwana" i w związku z tym może zamieniać kopiowanie
na przesuwanie gdy to jest dozwolone. Jest wymagany ponieważ deklaracja konstruktora kopiującego niejawnie usuwa deklarację
konstruktora przenoszącego.
*/
