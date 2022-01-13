#include "MapPoint.h"

MapPoint::MapPoint(double x, double y, int radius, RGBA color)
    : Punkt2(x, y)
    , visRadius { radius }
    , visColor { color } { }

MapPoint::MapPoint()
    : MapPoint(0.0, 0.0, 0, { 0, 0, 0 }) { }

// operator<<
std::ostream& operator<<(std::ostream& os, const MapPoint& obj) {
    Punkt2 const& p = static_cast<Punkt2 const&>(obj); // rzutowanie na klasę bazową
    os << p << " " << obj.getVisColor() << " width(" << obj.getVisRadius() << ")\n";

    return os;
}
