#pragma once

#include "Punkt2.h"
#include "RGBA.h"

#include <initializer_list>
#include <vector>

class MapChain {
public:
    enum class Type {
        Road,
        Rails,
        Powerline,
        //...
    };

    MapChain(Type type, std::initializer_list<Punkt2> points, int width, RGBA color);

    Punkt2& operator[](size_t o) { return m_points[o]; }
    Punkt2 const& operator[](size_t o) const { return m_points[o]; }

    Type type() const { return m_type; }
    std::vector<Punkt2> const& points() const { return m_points; }

    int width() const { return m_width; }
    void set_width(int o) { m_width = std::move(o); }
    RGBA color() const { return m_color; }
    void set_color(RGBA o) { m_color = std::move(o); }

private:
    friend std::ostream& operator<<(std::ostream&, MapChain const&);

    Type m_type {};
    std::vector<Punkt2> m_points;
    int m_width {};
    RGBA m_color {};
};
