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

Punkt2 make_point(double x, double y)
{
    Punkt2 p;
    p.setX(x);
    p.setY(y);
    return p;
}

int main()
{
    // Punkt2

    Punkt2 p1;
    p1.setX(10.0);

    //1
    p1.setY(20.5);

    //2
    Punkt2* p2 = new Punkt2();
    p2->setX(11);
    p2->setY(60.7);

    //3
    std::cout << "3. d = " << p1.getDistance(*p2) << std::endl;

    //4
    std::cout << "4. d = " << p1.getDistance(*p2) << std::endl;

    //5
    std::cout << "5. r=" << p2->getRadius() << ", a=" << p2->getAngle() << " [rad]" << std::endl;

    delete p2;

    //6
    std::cout << "6. sizeof(p1) == " << sizeof(p1) << std::endl;

    // Polygon
    Polygon pol;
    pol.setCount(4);
    pol.vertices()[0] = make_point(0, 0);
    pol.vertices()[1] = make_point(10, 0);
    pol.vertices()[2] = make_point(10, 10);
    pol.vertices()[3] = make_point(0, 10);
    pol.changeVertex(3, 0, -10);

    std::cout << "Obwód: " << pol.getPerimeter() << std::endl;

    return 0;
}
