#include "MapChain.h"

MapChain::MapChain(Type type, std::initializer_list<Punkt2> points, int width, RGBA color)
    : m_type(type)
    , m_points(points)
    , m_width(width)
    , m_color(std::move(color)) {
}

std::ostream& operator<<(std::ostream& out, MapChain const& chain) {
    out << "MapChain type=" << (int)chain.m_type << " points={";
    for (size_t s = 0; s < chain.m_points.size(); s++) {
        out << chain.m_points[s];
        if (s != chain.m_points.size() - 1)
            out << ",";
    }
    return out << "}";
}
