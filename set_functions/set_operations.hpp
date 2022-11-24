#include <set>
#include <type_traits>
#include <concepts>

template <class T>
std::set<T> operator+(const std::set<T> &A, const std::set<T> &B)
{
    std::set<T> C;
    for (auto i : A)
    {
        C.insert(i);
    }
    for (auto i : B)
    {
        C.insert(i);
    }
    return C;
}

std::set<T> operator-(const std::set<T> &A, const std::set<T> &B)
{
    std::set<T> C;
    for (auto i : B)
    {
        C.insert(i);
    }
    for (auto i : B)
    {
        C.erase(i);
    }
    return C;
}

std::set<T> operator^=(const std::set<T> &A, const std::set<T> &B)
{
    std::set<T> C;
    for (auto i : A)
    {
        C.insert(i);
    }
    for (auto i : B)
    {
        if (C.count(i) == 0)
            C.insert(i);
        else
            C.erase(i);
    }
    return C;
}

std::set<T> operator*(const std::set<T> &A, const std::set<T> &B)
{
    std::set<T> C;
    for (auto i : A)
    {
        for (auto j : B)
        {
            C.insert(i + j);
        }
    }
    return C;
}

std::set<T> operator^(const std::set<T> &A, const int n)
{
    std::set<T> C = A;
    for (auto i = 1; i < n; i++)
    {
        C = C * A;
    }
    return C;
}

