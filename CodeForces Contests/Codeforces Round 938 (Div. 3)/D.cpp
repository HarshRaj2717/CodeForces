#include <bits/stdc++.h>

using namespace std;

int solver(int n, int m, int k, vector<int> &a, vector<int> &b)
{
    unordered_map<int, int> toAdd;
    unordered_map<int, int> toRemove;
    int toAddSize = b.size();
    int toRemoveSize = 0;
    for (int i : b)
    {
        toAdd[i]++;
    }
    int ans = 0;
    int s = 0;
    int e = 0;
    for (; e < m; e++)
    {
        if (toAdd[a[e]] == 0)
        {
            toRemove[a[e]]++;
            toRemoveSize++;
        }
        else
        {
            toAdd[a[e]]--;
            toAddSize--;
        }
    }
    if (m - toAddSize >= k)
    {
        ans++;
    }
    while (e < a.size())
    {
        if (toRemove[a[s]] == 0)
        {
            toAdd[a[s]]++;
            toAddSize++;
        }
        else
        {
            toRemove[a[s]]--;
            toRemoveSize--;
        }
        if (toAdd[a[e]] == 0)
        {
            toRemove[a[e]]++;
            toRemoveSize++;
        }
        else
        {
            toAdd[a[e]]--;
            toAddSize--;
        }
        s++;
        e++;
        if (m - toAddSize >= k)
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        vector<int> b(m);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        cout << solver(n, m, k, a, b) << endl;
    }
    return 0;
}