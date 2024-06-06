#include <bits/stdc++.h>

using namespace std;

long long solver(long long x, long long y)
{
    int cur = 0;
    for (; cur < 35; cur++)
    {
        if ((x & (1 << cur)) != (y & (1 << cur)))
            break;
    }
    return 1ll << cur;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x;
        long long y;
        cin >> x >> y;

        cout << solver(x, y) << endl;
    }
    return 0;
}