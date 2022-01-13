/*! \file Polygon.h
 *
 * \brief Zawiera deklarację klasy Polygon
 *
 * \author Maciej Zygmanowski
 * \date 2022-01-13
 * \version 1.0.0
 */

#pragma once

#include "Punkt2.h"

#include <cstddef>
#include <vector>

class Polygon {
public:
    Polygon();

    /// \brief Konstruktor z wektorem wektorów współrzędnych.
    /// Konstruktor wymaga, aby każdy podwektor miał wielkość 2.
    /// \example auto Polygon {{0,0}, {10,0}, {10,10}, {0,10}};
    /// \sa Polygon(std::vector<Point> const& data)
    explicit Polygon(std::vector<std::vector<double>> const& data);

    /// \brief Konstruktor z wektorem punktów
    /// \example auto Polygon {{0,0}, {10,0}, {10,10}, {0,10}};
    /// \sa Polygon(std::vector<std::vector<double>> const& data)
    explicit Polygon(std::vector<Punkt2> data);

    ~Polygon();

    //! Metoda konstruująca tablicę wierzchołków.
    /*!
        Dane są kopiowane z podanej tablicy.
        \param _vertices  argument typu Punkt*  przekazujący tablicę wierzchołków wielokąta
        \param _count argument typu  unsigned int przekazujący ilość wierzchołków.
        \sa changeVertex()
    */
    void setVertices(Punkt2* _vertices, int _count);

    //! Metoda zmieniająca wspólrzędne i-tego wierzchołka.
    /// UWAGA: Funkcja nie sprawdza wychodzenia poza zakres tablicy.
    /*!
        \param i argument typu int przekazujący numer wierchołka do zmiany
        \param x argument typu double przekazujący nową wartość do współrzędnej x.
        \param y argument typu double przekazujący nową wartość do współrzędnej y.
        \sa setVertices()
    */
    void changeVertex(int i, double x, double y);

    //! Metoda ustawiająca ilość wierzchołków.
    /*!
        Jeżeli nowa wielkość jest większa od obecnej, nowe wierzchołki są
        inicjalizowane do wartości [0,0].
        \param n argument typu size_t przekazujący ilość wierchołków
        \sa setVertices()
    */
    void setCount(size_t n);

    //! Metoda zwraca obwód wielokąta.
    double getPerimeter();

    //! Zwróć wskaźnik na dane przechowywane przez obiekt.
    Punkt2* vertices();

    /// \brief Oblicz pole figury, zakładając że jest wypukła.
    ///
    /// UWAGA: Ta metoda może zwracać nieprawidłowe wyniki dla figur wklęsłych.
    /// \returns 0, jeżeli figura ma mniej niż 3 wierzchołki, w przeciwnym
    /// razie pole figury.
    double getConvexArea() const;

    /// \brief Oblicz pole dowolnej figury, wykorzystując Shoelace formula.
    /// \returns 0, jeżeli figura ma mniej niż 3 wierzchołki.
    /// razie pole figury.
    double getArea() const;

    /// \brief Ilość aktualnie żyjących obiektów.
    static size_t getObjectCount() { return object_count; }

private:
    double getTriangleArea(Punkt2 p1, Punkt2 p2, Punkt2 p3) const;

    size_t m_count {};
    Punkt2* m_vertices {};

    static size_t object_count;
};
