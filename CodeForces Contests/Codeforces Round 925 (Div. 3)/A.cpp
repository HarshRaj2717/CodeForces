#include <bits/stdc++.h>

using namespace std;

vector<int> solver(int n)
{
    n -= 3;
    vector<int> ans(3, 0);
    for (int i = 2; i >= 0; i--)
    {
        if (n > 25)
        {
            n -= 25;
            ans[i] = 25;
        }
        else
        {
            ans[i] = n;
            return ans;
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
        int n;
        cin >> n;
        vector<int> ans = solver(n);
        for (int i : ans)
        {
            char t = 'a' + i;
            cout << t;
        }
        cout << endl;
    }
    return 0;
}