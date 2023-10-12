#include <bits/stdc++.h>

using namespace std;

int solver(string x, string s)
{
    int n = 0;
    while (x.size() <= 3 * s.size() || n < 2)
    {
        if (x.find(s) != string::npos)
            return n;
        x += x;
        n++;
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        cin.ignore();
        string x;
        cin >> x;
        string s;
        cin.ignore();
        cin >> s;
        cout << solver(x, s) << endl;
    }
    return 0;
}