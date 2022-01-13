/*! \file Polygon.cpp
 *
 * \brief Zawiera implementację klasy Polygon
 *
 * \author Maciej Zygmanowski
 * \date 2022-01-13
 * \version 1.0.0
 */

#include "Polygon.h"
#include "Punkt2.h"

void Polygon::setVertices(Punkt2* _vertices, int _count) {
    // powinniśmy je skopiować bo nie wiadomo czy będą istnieć potem
    delete[] m_vertices;
    m_vertices = new Punkt2[_count];
    for (size_t s = 0; s < _count; s++) {
        m_vertices[s] = _vertices[s];
    }
    m_count = _count;
}

void Polygon::changeVertex(int i, double x, double y) {
    Punkt2 p;
    p.setX(x);
    p.setY(y);
    m_vertices[i] = p;
}

void Polygon::setCount(int n) {
    if (m_count < n) {
        auto old_vertices = m_vertices;
        m_vertices = new Punkt2[n];
        for (size_t s = 0; s < n; s++) {
            if(s < m_count)
                m_vertices[s] = old_vertices[s];
            else
                m_vertices[s] = {};
        }
        delete[] old_vertices;
    }
    m_count = n;
}

double Polygon::getPerimeter() {
    double p {};
    for (size_t s = 0; s < m_count; s++) {
        auto diff = m_vertices[s].getDistance(m_vertices[(s + 1) % m_count]);
        p += diff;
    }
    return p;
}

Punkt2* Polygon::vertices() {
    return m_vertices;
}
