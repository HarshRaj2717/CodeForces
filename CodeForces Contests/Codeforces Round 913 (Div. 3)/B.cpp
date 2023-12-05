#include <bits/stdc++.h>

using namespace std;

string solver(string s)
{
    stack<int> lower, upper;
    string ans;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'B')
        {
            s[i] = ' ';
            if (!upper.empty())
            {
                s[upper.top()] = ' ';
                upper.pop();
            }
            continue;
        }
        if (s[i] == 'b')
        {
            s[i] = ' ';
            if (!lower.empty())
            {
                s[lower.top()] = ' ';
                lower.pop();
            }
            continue;
        }
        if (s[i] >= 'a' && s[i] <= 'z')
            lower.push(i);
        else
            upper.push(i);
    }
    for (auto i : s)
    {
        if (i == ' ')
            continue;
        ans.push_back(i);
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << solver(s) << endl;
    }
    return 0;
}