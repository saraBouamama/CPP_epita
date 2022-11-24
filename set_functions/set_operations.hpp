#include <set>
#include <type_traits>
#include <concepts>

template <class T>
std::set<T> operator+(const std::set<T> &A, const std::set<T> &B)
{
    std::set<T> C;
    for (const auto i : A)
    {
        C.insert(i);
    }
    for (const auto i : B)
    {
        C.insert(i);
    }
    return C;
}

template <class T>
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

template <class T>
std::set<T> operator^(const std::set<T> &A, const std::set<T> &B)
{
    std::set<T> C;
    for (const auto i : A)
    {
        C.insert(i);
    }
    for (const auto i : B)
    {
        if (C.find(i) != C.end())
            C.erase(i);
        else
            C.insert(i);
    }
    return C;
}

template <class T>
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

int floor_function(int n)
{
    while (n > 0)
    {
        n--;
    }
    return n;
}

template <class T>
std::set<T> operator^(const std::set<T> &A,int number)
{
    if (number < 0 || floor_function(number) < 0)
        throw std::invalid_argument("received float value");
    auto new_set = std::set<T>{};
    if (number == 0)
    {
        return A;
    }
    new_set = new_set + A;
    while (number >= 2)
    {
        new_set = new_set * A;
        number = number - 1;
    }
    return new_set;
}
