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
#include <ostream>
#include <vector>

class Polygon {
public:
    Polygon();

    /// \brief Konstruktor z wektorem wektorów współrzędnych.
    /// Konstruktor wymaga, aby każdy podwektor miał wielkość 2.
    /// \example auto Polygon {{0,0}, {10,0}, {10,10}, {0,10}};
    /// \sa Polygon(std::vector<Point> const& data)
    Polygon(std::vector<std::vector<double>> const& data);

    /// \brief Konstruktor z wektorem punktów
    /// \example auto Polygon {{0,0}, {10,0}, {10,10}, {0,10}};
    /// \sa Polygon(std::vector<std::vector<double>> const& data)
    explicit Polygon(std::vector<Punkt2> data);

    /// \brief Konstruktor klasy Punkt2 z std::initializer list
    /// \example Punkt2 p {10, 1};
    Polygon(std::initializer_list<Punkt2>);

    /// \brief Konstruktor kopiujący. Wykonuje kopię głęboką.
    Polygon(Polygon const&);

    /// \brief Kopiujący operator przypisania. Wykonuje kopię głęboką.
    Polygon& operator=(Polygon const&);

    /// \brief Konstruktor przenoszący.
    Polygon(Polygon&&);

    /// \brief Przenoszący operator przypisania.
    Polygon& operator=(Polygon&&);

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
    double getPerimeter() const;

    //! Zwróć wskaźnik na dane przechowywane przez obiekt.
    Punkt2* vertices();

    //! Zwróć wskaźnik na dane przechowywane przez obiekt.
    Punkt2 const* vertices() const;

    /// \returns Ilość wierzchołków.
    size_t getVertexCount() const { return m_count; }

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

    /// \returns Wierzchołek o indeksie podanym jako argument.
    /// UWAGA: Funkcja nie sprawdza wychodzenia poza zakres tablicy.
    Punkt2 getVertex(size_t) const;

    /// \returns Referencję do wierzchołka o indeksie podanym jako argument.
    /// UWAGA: Funkcja nie sprawdza wychodzenia poza zakres tablicy.
    Punkt2& operator[](size_t);

    /// \returns Referencję do wierzchołka o indeksie podanym jako argument.
    /// UWAGA: Funkcja nie sprawdza wychodzenia poza zakres tablicy.
    Punkt2 const& operator[](size_t) const;

private:
    /// \brief Operator wypisywania obiektu klasy Polygon.
    ///
    /// Do obsługi np. strumienia std::cout.
    friend std::ostream& operator<<(std::ostream&, Polygon const&);

    double getTriangleArea(Punkt2 p1, Punkt2 p2, Punkt2 p3) const;

    size_t m_count {};
    Punkt2* m_vertices {};

    static size_t object_count;
};
