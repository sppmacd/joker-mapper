/*! \file RGBA.h
 *
 * \brief Zawiera deklarację klasy RGBA
 *
 * \author Maciej Zygmanowski
 * \date 2022-01-13
 * \version 1.0.0
 */

#pragma once

#include <cstdint>
#include <ostream>

class RGBA {
public:
    RGBA()
        : RGBA({}, {}, {}) { }

    /// \brief Constructor from components in range <0, 1>.
    RGBA(float _r, float _g, float _b, float _a = 1)
        : m_r(_r)
        , m_g(_g)
        , m_b(_b)
        , m_a(_a) { }

    /// \returns Red value in range <0;1>
    float r() const { return m_r; }

    /// \returns Green value in range <0;1>
    float g() const { return m_g; }

    /// \returns Blue value in range <0;1>
    float b() const { return m_b; }

    /// \returns Alpha value in range <0;1>
    float a() const { return m_a; }

    /// \returns Red value in range <0;2 ^ bytes - 1>
    /// \param bytes - Byte range (e.g 8 for 0-255)
    int r_bytes(int bytes = 8) const { return m_r * ((1 << bytes) - 1); }

    /// \returns Green value in range <0;2 ^ bytes - 1>
    /// \param bytes - Byte range (e.g 8 for 0-255)
    int g_bytes(int bytes = 8) const { return m_g * ((1 << bytes) - 1); }

    /// \returns Blue value in range <0;2 ^ bytes - 1>
    /// \param bytes - Byte range (e.g 8 for 0-255)
    int b_bytes(int bytes = 8) const { return m_b * ((1 << bytes) - 1); }

    /// \returns Alpha value in range <0;2 ^ bytes - 1>
    /// \param bytes - Byte range (e.g 8 for 0-255)
    int a_bytes(int bytes = 8) const { return m_a * ((1 << bytes) - 1); }

    bool operator==(const RGBA& other) const { return other.r() == r() && other.g() == g() && other.b() == b() && other.a() == a(); }
    bool operator!=(const RGBA& other) const { return !(*this == other); }
    RGBA operator+(const RGBA& other) const { return RGBA(r() + other.r(), g() + other.g(), b() + other.b(), a() + other.a()); }
    RGBA operator-(const RGBA& other) const { return RGBA(r() - other.r(), g() - other.g(), b() - other.b(), a() - other.a()); }
    RGBA operator*(double d) const { return RGBA(r() * d, g() * d, b() * d, a() * d); }
    RGBA operator/(double d) const { return RGBA(r() * d, g() * d, b() * d, a() * d); }

private:
    friend std::ostream& operator<<(std::ostream&, RGBA const&);

    float m_r, m_g, m_b, m_a;
};
