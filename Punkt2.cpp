/*! \file Punkt2.cpp
*
* \brief Zawiera definicję klasy Punkt2
*
* Plik zawiera implementację metod klasy Punkt2.
*
* \author Maciej Zygmanowski
* \date 2022-01-13
* \version 1.0.0
*/

#include "Punkt2.h"

#include <cmath>

//settery
void Punkt2::setX(double _x)
{
    x = _x;
}
void Punkt2::setY(double _y)
{
    y = _y;
}

//gettery
double Punkt2::getX()
{
    return x;
}
double Punkt2::getY()
{
    return y;
}

//współrzędne biegunowe
double Punkt2::getRadius()
{
    return std::sqrt(x*x+y+y);
}
double Punkt2::getAngle()
{
    return std::atan2(y, x);
}

//odległość punktu od punktu _p
double Punkt2::getDistance(Punkt2 _p)
{
    Punkt2 p;
    p.setX(_p.getX() - getX());
    p.setY(_p.getY() - getY());
    return p.getRadius();
}
