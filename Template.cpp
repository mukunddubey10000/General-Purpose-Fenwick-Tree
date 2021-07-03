#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct Fenwick
{
    vector<T> BIT;
    //Using vector to store the prefix values
    int n;
    Fenwick(int n)
    {
        this->n = n + 1;
        BIT.assign(n + 1, 0);
    }
    void update(int index, T value)
    {
        //point update
        //pass just the index where the value has
        //to be updated which also influences the
        //other indices to change their prefix values
        int pos = index;
        for (++pos; pos <= n; pos += pos & -pos)
            BIT[pos] += value;
    }
    void rangeupdate(int l, int r, T value)
    {
        //same as point update but in a range for all
        //elements falling in the range of l->r
        update(r + 1, -value);
        update(l, value);
    }
    T query(int index)
    {
        //to get the sum from the 1st element to the
        //element in the given index
        T value = 0;
        int pos = index;
        for (++pos; pos > 0; pos -= pos & -pos)
            value += BIT[pos];
        return value;
    }
    T rangequery(int l, int r)
    {
        //to get the prefix sum of a range of elements
        T value = query(r + 1) - query(l);
        return value;
    }
};