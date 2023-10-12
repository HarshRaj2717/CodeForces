#include <bits/stdc++.h>

using namespace std;

bool solver(int a, int b, int c)
{
    vector<int> temp = {a, b, c};

    sort(temp.begin(), temp.end());
    if (temp[2] % temp[0] != 0 || temp[1] % temp[0] != 0)
        return false;

    int n = 3;
    n -= int(temp[2] / temp[0]) - 1;
    n -= int(temp[1] / temp[0]) - 1;

    return n >= 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        solver(a, b, c) ? cout << "YES" : cout << "NO";
        cout << endl;
    }
    return 0;
}