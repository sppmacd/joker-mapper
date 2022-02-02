// deklaracja klasy MapPoint - plik MapPoint.h
#pragma once

#include "Punkt2.h"
#include "RGBA.h"

class MapPoint : public Punkt2 // po dwukropku podajemy klasę, którą dziedziczy klasa MapPoint
{
    int visRadius; // promień koła reprezentującego punkt na mapie (w pikselach)

    RGBA visColor; // kolor koła reprezentującego punkt na mapie

    // teraz klasa MapPoint posiada cztery składowe materialne: x,y, visRadius, visColor

public:
    MapPoint();
    MapPoint(double x, double y, int radius, RGBA color);

    void setVisRadius(int r) { visRadius = r; }
    void setVisColor(RGBA color) { visColor = color; }

    int getVisRadius() const { return visRadius; }
    RGBA getVisColor() const { return visColor; }

    explicit operator int() const { return visRadius; }
    operator RGBA() const { return visColor; }

private:
    friend std::ostream& operator<<(std::ostream& os, const MapPoint& obj);
};

// Lab 35, zad 4
class MapPointInherited : public Punkt2, public RGBA
{
public:
    /// Construct MapPointInherited from point and color.
    /// \param point
    /// \param color
    MapPointInherited(Punkt2 p, RGBA rgba)
    : Punkt2(p), RGBA(rgba) {}

    /// Convert this object to underlying Punkt2.
    Punkt2 punkt() const { return (Punkt2)*this; }

    /// Convert this object to underlying color.
    RGBA color() const { return (RGBA)*this; }
};
