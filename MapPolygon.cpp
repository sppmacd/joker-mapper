/*! \file MapPolygon.cpp
 *
 * \brief Zawiera implementację klasy MapPolygon
 *
 * \author Maciej Zygmanowski
 * \date 2022-01-13
 * \version 1.0.0
 */

#include "MapPolygon.h"

std::ostream& operator<<(std::ostream& out, MapPolygon const& polygon)
{
    return out << "MapPolygon{" << static_cast<Polygon const&>(polygon)
        << " border_width = " << polygon.m_border_width
        << " border_color = " << polygon.m_border_color
        << " fill_color = " << polygon.m_fill_color
        << " opacity = " << polygon.m_opacity
        << "}";
}
