#include <bits/stdc++.h>

using namespace std;

vector<int> solver(int n, int k)
{
    vector<int> ans;
    int cur = 1;

    while (k--)
    {
        ans.push_back(cur);
        cur++;
    }

    while (n >= cur)
    {
        ans.push_back(n);
        n--;
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n;
        cin >> k;
        vector<int> ans = solver(n, k);
        for (int i : ans)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}