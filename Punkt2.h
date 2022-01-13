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

#include <cstddef>

class Punkt2 {
    double x { 0.0 };
    double y { 0.0 };

public:
    Punkt2() { object_count++; }

    /// \brief Konstruktor klasy Punkt2.
    /// \param x_
    /// \param y_
    Punkt2(double x_, double y_);

    ~Punkt2();

    /// \brief Ustaw współrzędną X punktu
    /// \param _x
    void setX(double _x);

    /// \brief Ustaw współrzędną Y punktu
    /// \param _y
    void setY(double _y);

    /// \returns Współrzędna X punktu
    double getX();

    /// \returns Współrzędna Y punktu
    double getY();

    /// \returns Promień (odległość od początku układu współrzędnych)
    double getRadius();

    /// \returns Kąt punktu (atan2(x,y))
    double getAngle();

    /// \param _p - Inny punkt
    /// \returns Odległość od punktu `p`
    double getDistance(Punkt2 _p);

    /// \brief Ilość aktualnie żyjących obiektów.
    static size_t getObjectCount() { return object_count; }

private:
    static size_t object_count;
};
