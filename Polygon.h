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

class Polygon {
public:
    //! Metoda konstruująca tablicę wierzchołków.
    /*!
        Dane są kopiowane z podanej tablicy.
        \param _vertices  argument typu Punkt*  przekazujący tablicę wierzchołków wielokąta
        \param _count argument typu  unsigned int przekazujący ilość wierzchołków.
        \sa changeVertex()
    */
    void setVertices(Punkt2* _vertices, int _count);

    //! Metoda zmieniająca wspólrzędne i-tego wierzchołka.
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
        \param n argument typu int przekazujący ilość wierchołków
        \sa setVertcies()
    */
    void setCount(int n);

    //! Metoda zwraca obwód wielokąta.
    double getPerimeter();

    //! Zwróć wskaźnik na dane przechowywane przez obiekt.
    Punkt2* vertices();

    //! Oblicz pole figury, zakładając że jest wypukła.
    ///
    /// UWAGA: Ta metoda może zwracać nieprawidłowe wyniki dla figur wklęsłych.
    /// \returns 0, jeżeli figura ma mniej niż 3 wierzchołki, w przeciwnym
    /// razie pole figury.
    double getConvexArea() const;

    //! Oblicz pole dowolnej figury, wykorzystując Shoelace formula.
    /// \returns 0, jeżeli figura ma mniej niż 3 wierzchołki.
    /// razie pole figury.
    double getArea() const;

private:
    double getTriangleArea(Punkt2 p1, Punkt2 p2, Punkt2 p3) const;

    size_t m_count {};
    Punkt2* m_vertices {};
};
