// Do not change
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <deque>
#include <cstring>
#include <tuple>

#include "my_sort.hpp"

template <class T, class X>
void read_file_to_cont(std::ifstream &f, X &c)
{
    if constexpr (std::is_same<X, char>::value)
    {
        char ch;
        while (f.get(ch))
        {
            c.push_back(ch);
            f.get();
        }
    }
    else
    {
        T iterator;
        while (f >> iterator)
        {
            c.push_back(iterator);
        }
    }
}

template <class T, class X>
void read_and_sort(std::ifstream &fi, std::ofstream &fo)
{
    X result = {};
    read_file_to_cont<T, X>(fi, result);
    if constexpr (std::is_integral_v<T>)
    {
        my_selection_sort(result.begin(), result.end(), [](int l, int r) -> bool
                          { return std::make_tuple(l % 2, l) < std::make_tuple(r % 2, r); });
    }
    else
    {
        my_selection_sort(result.begin(), result.end(), [](T l, T r) -> bool
                          { return l > r; });
    }
    for (auto &i : result)
    {
        fo << i << std::endl;
    }
}

template <class T>
void read_and_sort_decide_container(std::ifstream &fi, std::ofstream &fo)
{
    char secondLine;
    fi >> secondLine;
    fo << secondLine << std::endl;
    switch (secondLine)
    {
    // Case for: Vector
    case 'v':
        read_and_sort<T, std::vector<T>>(fi, fo);
        break;
    // Case for: list
    case 'l':
        read_and_sort<T, std::list<T>>(fi, fo);
        break;
    // Case for: deque
    case 'd':
        read_and_sort<T, std::deque<T>>(fi, fo);
        break;
    }
}

void read_and_sort_decide_valuetype(std::ifstream &fi, std::ofstream &fo)
{
    char line;
    fi >> line;
    fo << line << std::endl;
    switch (line)
    {
    // Case for: Char
    case 'c':
        read_and_sort_decide_container<char>(fi, fo);
        break;
    // Case for: int
    case 'i':
        read_and_sort_decide_container<int>(fi, fo);
        break;
    // Case for: string
    case 's':
        read_and_sort_decide_container<std::string>(fi, fo);
        break;
    // Case for: float
    case 'f':
        read_and_sort_decide_container<float>(fi, fo);
        break;
    // Case for: unsigned
    case 'u':
        read_and_sort_decide_container<unsigned>(fi, fo);
        break;
    // Case for: double
    case 'd':
        read_and_sort_decide_container<double>(fi, fo);
        break;
    }
}
