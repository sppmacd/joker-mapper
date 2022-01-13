/*! \file Punkt2.h
*
* \brief Zawiera deklarację klasy Punkt2
*
* Plik zawiera deklarację klasy Punkt2.h.
* Współrzędne punktu są podawane w układzie kartezjańskim.
* Klasa zawiera kilka metod skladowych
*
* \author Maciej Zygmanowski
* \date 2022-01-13
* \version 1.0.0
*/

#pragma once

class Punkt2
{
    double x{0.0};
    double y{0.0};

public:
    //settery
    void setX(double _x);
    void setY(double _y);

    //gettery
    double getX();
    double getY();

    //współrzędne biegunowe
    double getRadius();
    double getAngle();

    //odległość punktu od punktu _p
    double getDistance(Punkt2 _p);
};
