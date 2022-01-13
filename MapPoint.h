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

private:
    friend std::ostream& operator<<(std::ostream& os, const MapPoint& obj);
};
