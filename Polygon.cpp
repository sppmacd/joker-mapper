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

#include <cassert>
#include <cmath>
#include <iostream>

size_t Polygon::object_count {};

#define LOG_CALL() std::cout << __PRETTY_FUNCTION__ << std::endl

Polygon::Polygon() {
    LOG_CALL();
    object_count++;
}

Polygon::Polygon(std::vector<std::vector<double>> const& data) {
    LOG_CALL();
    object_count++;
    setCount(data.size());
    for (size_t s = 0; s < data.size(); s++) {
        auto const& vertex = data[s];
        assert(vertex.size() == 2);
        m_vertices[s] = { vertex[0], vertex[1] };
    }
}

Polygon::Polygon(std::vector<Punkt2> data) {
    LOG_CALL();
    object_count++;
    setVertices(data.data(), data.size());
}

Polygon::Polygon(std::initializer_list<Punkt2> data) {
    LOG_CALL();
    object_count++;
    setCount(data.size());
    for (size_t s = 0; s < data.size(); s++)
        m_vertices[s] = data.begin()[s];
}

Polygon::Polygon(Polygon const& other) {
    LOG_CALL();
    object_count++;
    setVertices(other.m_vertices, other.m_count);
}

Polygon& Polygon::operator=(Polygon const& other) {
    LOG_CALL();
    if (this == &other)
        return *this;
    setVertices(other.m_vertices, other.m_count);
    return *this;
}

Polygon::~Polygon() {
    LOG_CALL();
    object_count--;
    delete[] m_vertices;
}

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

void Polygon::setCount(size_t n) {
    if (m_count < n) {
        auto old_vertices = m_vertices;
        m_vertices = new Punkt2[n];
        for (size_t s = 0; s < n; s++) {
            if (s < m_count)
                m_vertices[s] = old_vertices[s];
            else
                m_vertices[s] = {};
        }
        delete[] old_vertices;
    }
    m_count = n;
}

double Polygon::getPerimeter() const {
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

Punkt2 const* Polygon::vertices() const {
    return m_vertices;
}

Punkt2 Polygon::getVertex(size_t s) const {
    return m_vertices[s];
}

Punkt2& Polygon::operator[](size_t s) {
    return m_vertices[s];
}

Punkt2 const& Polygon::operator[](size_t s) const {
    return m_vertices[s];
}

double Polygon::getTriangleArea(Punkt2 p1, Punkt2 p2, Punkt2 p3) const {
    double a = p1.getDistance(p2);
    double b = p2.getDistance(p3);
    double c = p3.getDistance(p1);
    double p = (a + b + c) / 2;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

double Polygon::getConvexArea() const {
    if (m_count < 3)
        return 0;

    double P {};
    for (size_t s = 1; s < m_count - 1; s++)
        P += getTriangleArea(m_vertices[0], m_vertices[s], m_vertices[s + 1]);
    return P;
}

double Polygon::getArea() const {
    if (m_count < 3)
        return 0;

    // https://en.wikipedia.org/wiki/Shoelace_formula
    double p {};
    p += m_vertices[m_count - 1].getX() * m_vertices[0].getY();
    p -= m_vertices[0].getX() * m_vertices[m_count - 1].getY();

    for (size_t s = 0; s < m_count - 1; s++) {
        p += m_vertices[s].getX() * m_vertices[s + 1].getY();
        p -= m_vertices[s + 1].getX() * m_vertices[s].getY();
    }

    return std::abs(p) / 2;
}

std::ostream& operator<<(std::ostream& out, Polygon const& p) {
    out << "Polygon{";
    for (size_t s = 0; s < p.getVertexCount(); s++) {
        out << p.vertices()[s];
        if (s != p.getVertexCount() - 1)
            out << ", ";
    }
    return out << "}";
}
