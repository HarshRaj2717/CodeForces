#include <bits/stdc++.h>

using namespace std;

vector<int> solver(int n)
{
    vector<int> ans;
    int s = 1, e = n;
    while (s < e)
    {
        ans.push_back(s);
        ans.push_back(e);
        s++;
        e--;
    }
    if (s == e)
        ans.push_back(s);
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
        for (int i: ans)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}