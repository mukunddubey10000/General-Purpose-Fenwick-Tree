#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll t[500005];
void update(ll v, ll tl, ll tr, ll l, ll r, ll val)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[v] = max(t[v], val);
    }
    else
    {
        ll tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(r, tm), val);
        update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
    }
}

ll get(ll v, ll tl, ll tr, ll pos)
{

    if (tl == tr)
    {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    if (pos <= tm)
        return max(t[v], get(2 * v, tl, tm, pos));
    else
        return max(t[v], get(2 * v + 1, tm + 1, tr, pos));
}

int main()
{
    ll i, n, m;
    cin >> n >> m;

    while (m--)
    {
        ll x;
        cin >> x;
        if (x == 1)
        {
            ll l, r, v;
            cin >> l >> r >> v;
            r--;
            update(1, 0, n - 1, l, r, v);
        }
        else
        {
            ll y;
            cin >> y;
            cout << get(1, 0, n - 1, y) << "\n";
        }
    }

    return (0);
}