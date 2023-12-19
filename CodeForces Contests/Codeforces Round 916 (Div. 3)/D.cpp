// This is incorrect code
#include <bits/stdc++.h>

using namespace std;

int helper(int n, vector<int> &x, vector<int> &y, vector<int> &z, vector<int> &xx, vector<int> &yy, vector<int> &zz, int &xi, int &yi, int &zi, bool &mx, bool &my, bool &mz)
{
    int res;
    if (x[xx[xi]] > y[yy[yi]])
    {
        if (x[xx[xi]] > z[zz[zi]])
        {
            res = x[xx[xi]];
            x[xx[xi]] = 0;
            y[xx[xi]] = 0;
            z[xx[xi]] = 0;
            mx = false;
        }
        else
        {
            res = z[zz[zi]];
            x[zz[zi]] = 0;
            y[zz[zi]] = 0;
            z[zz[zi]] = 0;
            mz = false;
        }
    }
    else
    {
        if (y[yy[yi]] > z[zz[zi]])
        {
            res = y[yy[yi]];
            x[yy[yi]] = 0;
            y[yy[yi]] = 0;
            z[yy[yi]] = 0;
            my = false;
        }
        else
        {
            res = z[zz[zi]];
            x[zz[zi]] = 0;
            y[zz[zi]] = 0;
            z[zz[zi]] = 0;
            mz = false;
        }
    }

    if (x[xx[xi]] == 0 && mx)
        xi++;
    if (y[yy[yi]] == 0 && my)
        yi++;
    if (z[zz[zi]] == 0 && mz)
        zi++;
    return res;
}

int helper2(int n, vector<int> x, vector<int> y, vector<int> z, vector<int> &xx, vector<int> &yy, vector<int> &zz, int xi, int yi, int zi)
{
    int ans = 0;
    bool mx, my, mz;
    mx = my = mz = true;
    ans += helper(n, x, y, z, xx, yy, zz, xi, yi, zi, mx, my, mz);
    ans += helper(n, x, y, z, xx, yy, zz, xi, yi, zi, mx, my, mz);
    ans += helper(n, x, y, z, xx, yy, zz, xi, yi, zi, mx, my, mz);
    return ans;
}

int solver(int n, vector<int> &x, vector<int> &y, vector<int> &z)
{
    vector<int> xx, yy, zz;
    for (int i = 0; i < n; i++)
    {
        xx.push_back(i);
        yy.push_back(i);
        zz.push_back(i);
    }
    sort(xx.begin(), xx.end(), [x](int a, int b)
         { return x[a] > x[b]; });
    sort(yy.begin(), yy.end(), [y](int a, int b)
         { return y[a] > y[b]; });
    sort(zz.begin(), zz.end(), [z](int a, int b)
         { return z[a] > z[b]; });

    int xi, yi, zi;
    xi = yi = zi = 0;
    int ans = 0;

    ans = max({
        helper2(n, x, y, z, xx, yy, zz, xi, yi, zi),
        helper2(n, x, z, y, xx, zz, yy, xi, zi, yi),
        helper2(n, y, x, z, yy, xx, zz, yi, xi, zi),
        helper2(n, y, z, x, yy, zz, xx, yi, zi, xi),
        helper2(n, z, x, y, zz, xx, yy, zi, xi, yi),
        helper2(n, z, y, x, zz, yy, xx, zi, yi, xi),
    });

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> x(n), y(n), z(n);
        for (int i = 0; i < n; i++)
            cin >> x[i];
        for (int i = 0; i < n; i++)
            cin >> y[i];
        for (int i = 0; i < n; i++)
            cin >> z[i];
        cout << solver(n, x, y, z) << endl;
    }
    return 0;
}