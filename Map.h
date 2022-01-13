#pragma once

#include "MapChain.h"
#include "MapPolygon.h"
#include "MapPoint.h"

class Map
{
public:
    void add_chain(MapChain c) { m_chains.push_back(std::move(c)); }
    void add_point(MapPoint c) { m_points.push_back(std::move(c)); }
    void add_polygon(MapPolygon c) { m_polygons.push_back(std::move(c)); }
    
    std::vector<MapChain> const& chains() const { return m_chains; }
    std::vector<MapChain>& chains() { return m_chains; }
    
    std::vector<MapPoint> const& points() const { return m_points; }
    std::vector<MapPoint>& points() { return m_points; }
    
    std::vector<MapPolygon> const& polygons() const { return m_polygons; }
    std::vector<MapPolygon>& polygons() { return m_polygons; }

private:
    friend std::ostream& operator<<(std::ostream&, Map const&);

    std::vector<MapChain> m_chains;
    std::vector<MapPoint> m_points;
    std::vector<MapPolygon> m_polygons;
};
