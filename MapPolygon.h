/*! \file MapPolygon.h
 *
 * \brief Zawiera deklarację klasy MapPolygon
 *
 * \author Maciej Zygmanowski
 * \date 2022-01-13
 * \version 1.0.0
 */

#pragma once

#include "Polygon.h"
#include "RGBA.h"

class MapPolygon : public Polygon {
public:
    MapPolygon() = default;

    MapPolygon(std::initializer_list<Punkt2> points, int border_width, RGBA border_color, RGBA fill_color, int opacity)
        : Polygon(points)
        , m_border_width(border_width)
        , m_border_color(border_color)
        , m_fill_color(fill_color)
        , m_opacity(opacity) { }

    /// \returns Border width, in pixels
    int border_width() const { return m_border_width; }

    /// \returns Border color
    RGBA border_color() const { return m_border_color; }

    /// \returns Fill color
    RGBA fill_color() const { return m_fill_color; }

    /// \returns Opacity (in range <0, 255>)
    int opacity() const { return m_opacity; }

    /// \brief Set border width.
    /// \param v - Border width, in pixels
    void set_border_width(int v) { m_border_width = v; }

    /// \brief Set border color.
    /// \param v - Border color
    void set_border_color(RGBA v) { m_border_color = v; }

    /// \brief Set fill color.
    /// \param v - Fill color
    void set_fill_color(RGBA v) { m_fill_color = v; }

    /// \brief Set opacity.
    /// \param v - Opacity (in range <0, 255>)
    void set_opacity(int v) { m_opacity = v; }

private:
    friend std::ostream& operator<<(std::ostream&, MapPolygon const&);

    int m_border_width {};
    RGBA m_border_color;
    RGBA m_fill_color;
    int m_opacity { 255 };
};
