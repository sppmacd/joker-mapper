/*! \file main.cpp
 *
 * \brief Kod programu testującego klasę Map.
 *
 * \author Maciej Zygmanowski
 * \date 2022-01-13
 * \version 1.0.0
 */

#include "Map.h"

int main() {
    Map map;
    map.add_chain(MapChain { MapChain::Type::Road, { { 0, 0 }, { 10, 10 }, { 20, 20 } }, 1, RGBA { 0, 1, 0 } });
    map.add_chain(MapChain { MapChain::Type::Powerline, { { 10, 6 }, { 10, 2 }, { 20, 34 } }, 2, RGBA { 0, 1, 0, 0.4 } });
    map.add_chain(MapChain { MapChain::Type::Rails, { { 50, 7 }, { 65, 10 }, { 16, 20 } }, 2, RGBA { 1, 0, 0 } });
    map.add_point(MapPoint {});
    map.add_polygon(MapPolygon { MapPolygon::Type::Building, { { 0, 0 }, { 50, 3 }, { 12, 5 }, { 15, 9 }, { 12, 26 } }, 1, RGBA { 0, 0, 0 }, RGBA { 1, 1, 1, 0 }, 200 });
    std::cout << map << std::endl;

    MapPoint mp{10, 15, -54, {1, 0, 1, 0.5}};
    // int test1 = mp; // error: explicit conversion
    RGBA test2 = mp;
    std::cout << static_cast<int>(mp) << std::endl;
    std::cout << RGBA(mp) << std::endl;

    Polygon pol = std::vector<std::vector<double>> { { 0, 0 }, { 1, 1 }, { 2, 2 } };
    std::cout << pol << std::endl;
    return 0;
}
