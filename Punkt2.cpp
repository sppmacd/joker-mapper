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
#include <stdexcept>

size_t Punkt2::object_count {};

Punkt2::Punkt2(double x_, double y_)
    : x(x_)
    , y(y_) {
    object_count++;
    LOG_CALL();
}

Punkt2::Punkt2(std::initializer_list<double> p) {
    x = *(p.begin());
    y = *(p.begin() + 1);
    object_count++;
    LOG_CALL();
}

Punkt2::Punkt2(Punkt2 const& other)
    : x(other.x)
    , y(other.y) { LOG_CALL(); }

Punkt2::Punkt2(Punkt2&& other)
    : x(other.x)
    , y(other.y) { LOG_CALL(); }

Punkt2& Punkt2::operator=(Punkt2 const& other) {
    LOG_CALL();
    if (this == &other)
        return *this;
    x = other.x;
    y = other.y;
    return *this;
}

Punkt2& Punkt2::operator=(Punkt2&& other) {
    LOG_CALL();
    if (this == &other)
        return *this;
    x = other.x;
    y = other.y;
    return *this;
}

Punkt2::~Punkt2() {
    object_count--;
    LOG_CALL();
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
    if (x == 0 && y == 0)
        throw std::invalid_argument { "cannot compute angle for point (0,0)" };
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

std::ostream& operator<<(std::ostream& out, Punkt2 const& punkt) {
    return out << "[" << punkt.getX() << "," << punkt.getY() << "]";
}
