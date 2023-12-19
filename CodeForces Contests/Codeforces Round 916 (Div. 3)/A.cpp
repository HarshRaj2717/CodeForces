#include <bits/stdc++.h>

using namespace std;

int solver(string s)
{
    vector<int> m(26, 0);
    for (char i : s)
    {
        m[i - 'A']++;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (m[i] >= i + 1)
            ans++;
    }
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
        string s;
        cin >> s;
        cout << solver(s) << endl;
    }
    return 0;
}