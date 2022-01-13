#pragma once

#include "Punkt2.h"

#include <vector>
#include <initializer_list>

class MapChain {
public:
    MapChain() = default;

    MapChain(std::initializer_list<Punkt2> points);

    Punkt2& operator[](size_t o) { return m_points[o]; }

private:
    std::vector<Punkt2> m_points;
};
