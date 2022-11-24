// Change me instead
// All occurences of XXX need to be replaced with
// something more meaningful

template <typename T, class Z>
void my_selection_sort(T begin, T end, Z le_Z)
{
    for (T it = begin; it != end; ++it)
    {
        T res = it;
        for (T j = it; j != end; ++j)
        {
            if (le_Z(*j, *res))
            {
                res = j;
            }
        }
        // swapper
        auto tmp = *it;
        *it = *res;
        *res = tmp;
    }
}