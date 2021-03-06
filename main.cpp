/*! \file main.cpp
 *
 * \brief Kod programu testującego klasę Map.
 *
 * \author Maciej Zygmanowski
 * \date 2022-01-13
 * \version 1.0.0
 */

#include "Map.h"
#include "MapPoint.h"

int main() {
    Map map;
    map.add_chain(MapChain { MapChain::Type::Road, { { 0, 0 }, { 10, 10 }, { 20, 20 } }, 1, RGBA { 0, 1, 0 } });
    map.add_chain(MapChain { MapChain::Type::Powerline, { { 10, 6 }, { 10, 2 }, { 20, 34 } }, 2, RGBA { 0, 1, 0, 0.4 } });
    map.add_chain(MapChain { MapChain::Type::Rails, { { 50, 7 }, { 65, 10 }, { 16, 20 } }, 2, RGBA { 1, 0, 0 } });
    map.add_point(MapPoint {});
    map.add_polygon(MapPolygon { MapPolygon::Type::Building, { { 0, 0 }, { 50, 3 }, { 12, 5 }, { 15, 9 }, { 12, 26 } }, 1, RGBA { 0, 0, 0 }, RGBA { 1, 1, 1, 0 }, 200 });
    std::cout << map << std::endl;

    MapPoint mp { 10, 15, -54, { 1, 0, 1, 0.5 } };
    // int test1 = mp; // error: explicit conversion
    RGBA test2 = mp;
    std::cout << static_cast<int>(mp) << std::endl;
    std::cout << RGBA(mp) << std::endl;

    Polygon pol_global = std::vector<std::vector<double>> { { 0, 0 }, { 1, 1 }, { 2, 2 } };
    std::cout << pol_global << std::endl;

    {
        std::cout << "Lab 35 / 2 - test" << std::endl;
        Polygon pol1 {
            { 0, 0 }, { 1, 1 }, { 2, 2 }
        };
        Punkt2* arr = static_cast<Punkt2*>(pol1); // wymagane static_cast
        size_t count = pol1;                      // niewymagane static_cast
        for (size_t s = 0; s < count; s++)
            std::cout << arr[s] << std::endl; // ok
    }

    {
        std::cout << "Lab 35 / 3 - test" << std::endl;
        std::vector<std::vector<double>> verts {
            { 0, 0 },
            { 1, 1 },
            { 2, 2 }
        };
        Polygon pol1 { verts };
        size_t count = pol1; // niewymagane static_cast
        for (size_t s = 0; s < count; s++)
            std::cout << pol1[s] << std::endl; // ok
    }

    {
        std::cout << "Lab 35 / 4 - test" << std::endl;
        MapPointInherited mpi { { 5, 5 }, RGBA(1, 0, 1, 0) };
        std::cout << "punkt=" << mpi.getX() << "," << mpi.getY() << " color=" << mpi.r() << "," << mpi.g() << "," << mpi.b() << "," << mpi.a() << std::endl;
        std::cout << "punkt=" << mpi.punkt() << " color=" << mpi.color() << std::endl;
    }

#define EXCEPTION_TEST(...)                                                                            \
    try {__VA_ARGS__} catch (const char* c) { std::cout << "const char* exception: " << c << std::endl; } \
    catch (std::exception & e) {                                                                       \
        std::cout << "std::exception: " << e.what() << std::endl;                                      \
    }

    EXCEPTION_TEST({
        pol_global.getVertex(5);
    })

    EXCEPTION_TEST({
        pol_global.changeVertex(100, 2, 3);
    })

    EXCEPTION_TEST({
        Punkt2 {}.getAngle();
    })

#undef EXCEPTION_TEST
    return 0;
}
