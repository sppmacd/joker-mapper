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
    /*// Punkt2

    Punkt2 p1;
    p1.setX(10.0);

    // 1
    p1.setY(20.5);

    // 2
    Punkt2* p2 = new Punkt2();
    p2->setX(11);
    p2->setY(60.7);

    // 3
    std::cout << "3. d = " << p1.getDistance(*p2) << std::endl;

    // 4
    std::cout << "4. d = " << p1.getDistance(*p2) << std::endl;

    // 5
    std::cout << "5. r=" << p2->getRadius() << ", a=" << p2->getAngle() << " [rad]" << std::endl;

    delete p2;

    // 6
    std::cout << "6. sizeof(p1) == " << sizeof(p1) << std::endl;
    */

    // Punkt2 - konstruktory
    Punkt2 p1{0, 0};
    Punkt2 p2{0, 10};
    Punkt2 p3{10, 10};
    Punkt2 p4{10, 0};
    // Gdy to odkomentuję wypisze 0 ponieważ konstruktor kopiujący nie inkrementuje zmiennej
    // object_count, a skopiowany obiekt, który jest niszczony dekrementuje ją.
    //Polygon polZpkt {{p1, p2, p3, p4}};
    std::cout << "Ilość obiektów Punkt2: " << Punkt2::getObjectCount() << std::endl;

    // Polygon - konstruktory
    Polygon pol;
    Polygon pol2 {{
        std::vector<double>{0, 0},
        std::vector<double>{10, 0},
        std::vector<double>{5, 5},
        std::vector<double>{10, 10},
        std::vector<double>{-10, 10}
    }};
    std::cout << "pol2 (sprawdzenie inicjalizacji): " << std::endl;
    for(size_t s = 0; s < 5; s++)
        std::cout << "- " << pol2.vertices()[s].getX() << "," << pol2.vertices()[s].getY() << std::endl;
    std::cout << "Ilość obiektów Polygon: " << Polygon::getObjectCount() << std::endl;

    return 0;
}
