/*! \file Matrix.h
 *
 * \brief Zawiera deklarację klasy Matrix
 *
 * \author Maciej Zygmanowski
 * \date 2022-01-13
 * \version 1.0.0
 */

#pragma once

#include <cstddef>
#include <ostream>

class Matrix
{
public:
    Matrix() = default;
    ~Matrix();

    /// \brief Konstruktor przyjmujący wielkość macierzy.
    /// Elementy są inicjalizowane zerami.
    Matrix(size_t x, size_t y);

    /// \returns Wiersz macierzy określony w argumencie, bez sprawdzenia zakresu.
    double* operator[](size_t s) { return m_tab[s]; }

    /// \returns Element macierzy określony w argumentach, bez sprawdzenia zakresu.
    /// \param y - wiersz
    /// \param x - kolumna
    double& operator()(size_t y, size_t x) { return m_tab[x][y]; }

    size_t size_x() const { return m_sizex; }
    size_t size_y() const { return m_sizey; }

private:
    friend std::ostream& operator<<(std::ostream&, Matrix const&);

    double** m_tab {};
    size_t m_sizex {};
    size_t m_sizey {};
};
