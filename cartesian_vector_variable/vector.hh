#pragma once

#include <ostream>

#include "config.h"


class Vector
{
public:
// DO NOT CHANGE THIS
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;
//

// Add suitable constructors
    Vector();
    Vector(std::initializer_list<value> list);
    // possibly more

// Public Member functions here
    Vector& operator+=(const Vector& rhs);
    Vector& operator-=(const Vector& rhs);
    Vector operator+(const Vector &rhs);
    Vector operator-(const Vector &rhs);
    value operator*(const Vector &rhs);
    value operator[](size_t i) const;
    value& operator[](size_t i);
    size_t get_size() const;
    // More to go

private:
// Private Member functions here

// Member variables are ALWAYS private, and they go here
size_t dim;
value coord[NDIM];

};

// Nonmember function operators go here
Vector operator*(Vector &rhs, const value n);
Vector operator*=(Vector &rhs, const value n);
Vector operator+=(Vector &rhs, const value n);
std::ostream& operator<<(std::ostream &os, const Vector &rhs);
