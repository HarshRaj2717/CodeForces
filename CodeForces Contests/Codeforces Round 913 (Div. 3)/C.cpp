// This doesn't work...
#include <bits/stdc++.h>

using namespace std;

int solver(string s)
{
    int ans = 0;
    vector<int> m(26, 0);
    for (auto i: s)
        m[i - 'a']++;
    sort(m.begin(), m.end(), greater<int>());
    for (int i = 0; i < 26; i++)
    {
        if (m[i] == 0)
            continue;
        bool left = true;
        while (left && m[i] > 0)
        {
            left = false;
            for (int j = 0; j < 26 && m[i] > 0; j++)
            {
                if (j == i || m[j] == 0)
                    continue;
                m[j]--;
                m[i]--;
                if (m[j] > 0)
                    left = true;
            }
        }
    }
    for (int i: m)
    {
        ans += i;
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
        int _;
        cin >> _;
        cin >> s;
        cout << solver(s) << endl;
    }
    return 0;
}