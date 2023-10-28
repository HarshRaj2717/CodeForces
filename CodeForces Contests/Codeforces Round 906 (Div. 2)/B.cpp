#include <bits/stdc++.h>

using namespace std;

bool isGood(string &x)
{
    for (int i = 0; i < x.size() - 1; i++)
    {
        if (x[i] == x[i + 1])
            return false;
    }
    return true;
}

bool solver(string &s, string &t)
{
    if (isGood(s))
        return true;
    if (!isGood(t))
        return false;
    char t_left = t[0];
    char t_right = t[t.size() - 1];
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == s[i + 1] && (s[i] == t_left || s[i + 1] == t_right))
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int _;
        cin >> _ >> _;
        string s, t;
        cin.ignore();
        cin >> s;
        cin.ignore();
        cin >> t;

        solver(s, t) ? cout << "YES" << endl : cout << "NO" << endl;
    }

    return 0;
}