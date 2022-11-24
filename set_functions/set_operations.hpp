#include <set>
#include <type_traits>
#include <concepts>

template <class T>
std::set<T>& operator+( const std::set<T>& A, const std::set<T>& B)
{
    auto C;
    C = A.insert(B.begin(), B.end());
    return C;
}