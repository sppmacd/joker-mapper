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
#include <iostream>

size_t Punkt2::object_count {};

Punkt2::Punkt2(double x_, double y_)
    : x(x_)
    , y(y_) {
    object_count++;
}

Punkt2::~Punkt2() {
    object_count--;
    std::cout << "~Punkt2()" << std::endl;
}

// settery
void Punkt2::setX(double _x) {
    x = _x;
}
void Punkt2::setY(double _y) {
    y = _y;
}

// gettery
double Punkt2::getX() const {
    return x;
}
double Punkt2::getY() const {
    return y;
}

// współrzędne biegunowe
double Punkt2::getRadius() const {
    return std::sqrt(x * x + y * y);
}
double Punkt2::getAngle() const {
    return std::atan2(y, x);
}

// odległość punktu od punktu _p
double Punkt2::getDistance(Punkt2 _p) const {
    Punkt2 p;
    p.setX(_p.getX() - getX());
    p.setY(_p.getY() - getY());
    return p.getRadius();
}

Punkt2 Punkt2::operator+(Punkt2 const& other) const {
    return { x + other.x, y + other.y };
}

Punkt2 Punkt2::operator-(Punkt2 const& other) const {
    return { x - other.x, y - other.y };
}

double operator*(Punkt2 const& _1, Punkt2 const& _2) {
    return _1.getX() * _2.getX() + _1.getY() * _2.getY();
}
