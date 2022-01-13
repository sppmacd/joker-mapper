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
#include <iostream>

#define LOG_CALL() std::cout << __PRETTY_FUNCTION__ << std::endl

class Punkt2 {
    double x { 0.0 };
    double y { 0.0 };

public:
    /// \brief Konstruktor domyślny.
    Punkt2() {
        object_count++;
        LOG_CALL();
    }

    /// \brief Konstruktor kopiujący.
    Punkt2(Punkt2 const& other);

    /// \brief Konstruktor przesuwający.
    Punkt2(Punkt2&& other);

    /// \brief Kopiujący operator przypisania.
    Punkt2& operator=(Punkt2 const& other);

    /// \brief Przesuwający operator przypisania.
    Punkt2& operator=(Punkt2&& other);

    /// \brief Konstruktor klasy Punkt2.
    /// \param x_
    /// \param y_
    Punkt2(double x_, double y_);

    /// \brief Konstruktor klasy Punkt2 z std::initializer list
    /// \example Punkt2 p {10, 1};
    Punkt2(std::initializer_list<double>);

    ~Punkt2();

    /// \brief Ustaw współrzędną X punktu
    /// \param _x
    void setX(double _x);

    /// \brief Ustaw współrzędną Y punktu
    /// \param _y
    void setY(double _y);

    /// \returns Współrzędna X punktu
    double getX() const;

    /// \returns Współrzędna Y punktu
    double getY() const;

    /// \returns Promień (odległość od początku układu współrzędnych)
    double getRadius() const;

    /// \returns Kąt punktu (atan2(x,y))
    double getAngle() const;

    /// \param _p - Inny punkt
    /// \returns Odległość od punktu `p`
    double getDistance(Punkt2 _p) const;

    /// \brief Ilość aktualnie żyjących obiektów.
    static size_t getObjectCount() { return object_count; }

    /// \returns Suma wektora oraz argumentu
    Punkt2 operator+(Punkt2 const& other) const;

    /// \returns Różnica wektora oraz argumentu
    Punkt2 operator-(Punkt2 const& other) const;

private:
    static size_t object_count;
};

/// \returns Iloczyn skalarny (dot product) podanych punktów.
double operator*(Punkt2 const& _1, Punkt2 const& _2);

/// \brief Operator wypisywania obiektu klasy Punkt2.
///
/// Do obsługi np. strumienia std::cout.
std::ostream& operator<<(std::ostream&, Punkt2 const&);
