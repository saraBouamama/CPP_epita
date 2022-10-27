#include "vector.hh"
#include <ostream>
#include <iostream>

Vector::Vector()
{
    dim = NDIM;
    for (size_t i = 0; i < dim; i++)
    {
        coord[i] = 0;
    }
}

Vector::Vector(std::initializer_list<value> list)
{
    dim = list.size();
    size_t i = 0;
    for (auto &elem : list)
    {
        coord[i++] = elem;
    }
}

size_t Vector::get_size() const
{
    return dim;
}

Vector &Vector::operator+=(const Vector &rhs)
{
    for (size_t i = 0; i <  rhs.get_size(); i++)
    {
        coord[i] = coord[i] + rhs[i];
    }
    return *this;
}

Vector &Vector::operator-=(const Vector &rhs)
{
    for (size_t i = 0; i <  rhs.get_size(); i++)
    {
        coord[i] = coord[i] - rhs[i];
    }
    return *this;
}

Vector Vector::operator+(const Vector &rhs)
{
    auto v = Vector();
    for (size_t i = 0; i <  rhs.get_size(); i++)
    {
        v[i] = rhs[i] + (*this)[i];
    }
    return v;
}

Vector Vector::operator-(const Vector &rhs)
{
    auto v = Vector();
    for (size_t i = 0; i <  rhs.get_size(); i++)
    {
        v[i] = rhs[i] - (*this)[i];
    }
    return v;
}

value Vector::operator*(const Vector &rhs)
{
    value v = 0;
    for (size_t i = 0; i <  rhs.get_size(); i++)
    {
        v += rhs[i] * (*this)[i];
    }
    return v;
}

value Vector::operator[](size_t i) const
{
    return coord[i];
}

value &Vector::operator[](size_t i)
{
    return coord[i];
}

Vector operator*(Vector &rhs, const value n)
{
    auto v = Vector();
    for (size_t i = 0; i <  rhs.get_size(); i++)
    {
        v[i] = rhs[i] * n;
    }
    return v;
}

Vector operator*=(Vector &rhs, const value n)
{
    for (size_t i = 0; i <  rhs.get_size(); i++)
    {
        rhs[i] = rhs[i] * n;
    }
    return rhs;
}

Vector operator+=(Vector &rhs, const value n)
{
    for (size_t i = 0; i <  rhs.get_size(); i++)
    {
        rhs[i] = rhs[i] + n;
    }
    return rhs;
}

std::ostream& operator<<(std::ostream &os, const Vector& rhs)
{
    os << "{";
    for (int i = 0; i < rhs.get_size(); i++)
    {
        os << rhs[i] << (i == rhs.get_size() - 1 ? "" : ",");
    }
    return os << "}";
}
