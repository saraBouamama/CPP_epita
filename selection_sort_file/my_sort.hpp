// Change me instead
// All occurences of XXX need to be replaced with
// something more meaningful

template<typename T>
void my_selection_sort( T begin, T end) {
    T res;
    T iterator;
    for(T it = begin; it != end; ++it)
    {
        res = it;
        iterator = res;
        iterator++;

        for(; iterator != end; ++iterator)
        {
            if(*iterator < *res)
                res = iterator;
        }
        //swapper
        auto tmp = *it;
        *it = *res;
        *res = tmp;
    }
}