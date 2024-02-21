// Problem : https://codeforces.com/problemset/problem/1220/A
#include <bits/stdc++.h>

using namespace std;

string solver(string s)
{
    int n = 0, z = 0;
    for (auto i : s)
    {
        if (i == 'n')
            n++;
        else if (i == 'z')
            z++;
    }
    string ans = "";
    while (n-- > 0)
    {
        ans.push_back('1');
        ans.push_back(' ');
    }
    while (z-- > 0)
    {
        ans.push_back('0');
        ans.push_back(' ');
    }
    ans.pop_back();
    return ans;
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << solver(s);
    cout << endl;
    return 0;
}