#include "RGBA.h"

std::ostream& operator<<(std::ostream& out, RGBA const& color)
{
    return out << "rgba(" << color.r_bytes() << "," << color.g_bytes() << "," << color.b_bytes() << "," << color.a_bytes() << ")";
}
