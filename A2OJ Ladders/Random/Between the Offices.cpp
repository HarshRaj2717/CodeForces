// Problem : https://codeforces.com/problemset/problem/867/A
#include <bits/stdc++.h>

using namespace std;

bool solver(string s)
{
    int ss = 0, f = 0;
    int i = 0;
    while (i < s.size() - 1)
    {
        while (i < s.size() - 1 && s[i] == s[i + 1])
        {
            i++;
        }
        if (i == s.size() - 1)
        {
            break;
        }
        s[i+1] == 'F' ? f++ : ss++;
        i++;
    }
    return f > ss;
}

int main()
{
    int _;
    cin >> _;
    string s;
    cin >> s;
    solver(s) ? cout << "YES" : cout << "NO";
    cout << endl;
    return 0;
}