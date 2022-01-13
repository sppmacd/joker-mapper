#include "Map.h"

std::ostream& operator<<(std::ostream& out, Map const& map)
{
    out << "--- Map ---" << std::endl;
    out << "Chains:" << std::endl;
    for(auto const& o : map.chains())
        out << "- " << o << std::endl;
    out << "Points:" << std::endl;
    for(auto const& o : map.points())
        out << "- " << o << std::endl;
    out << "Polygons:" << std::endl;
    for(auto const& o : map.polygons())
        out << "- " << o << std::endl;
    return out;
}
