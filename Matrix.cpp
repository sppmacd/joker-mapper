/*! \file Matrix.cpp
 *
 * \brief Zawiera implementację klasy Matrix
 *
 * \author Maciej Zygmanowski
 * \date 2022-01-13
 * \version 1.0.0
 */

#include "Matrix.h"

Matrix::Matrix(size_t x, size_t y)
    : m_sizex(x)
    , m_sizey(y) {
    m_tab = new double*[y];
    for (size_t s = 0; s < y; s++) {
        m_tab[s] = new double[x] {};
    }
}

Matrix::~Matrix() {
    for (size_t s = 0; s < m_sizey; s++)
        delete[] m_tab[s];
    delete[] m_tab;
}

std::ostream& operator<<(std::ostream& out, Matrix const& mat) {
    if (mat.m_sizey == 0)
        return out << "{}";
    for (size_t y = 0; y < mat.m_sizey; y++) {
        out << "{ ";
        for (size_t x = 0; x < mat.m_sizex; x++) {
            out << mat.m_tab[y][x];
            if (x != mat.m_sizex - 1)
                out << ", ";
        }
        out << " }\n";
    }
    return out;
}
