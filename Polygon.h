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

private:
    size_t m_count {};
    Punkt2* m_vertices {};
};
