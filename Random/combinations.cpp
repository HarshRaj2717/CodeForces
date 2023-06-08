// Problem : https://leetcode.com/problems/combinations/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;

void solver(int n, int k, int cur, vector<int> cur_seq)
{
    if (cur_seq.size() == k)
    {
        ans.push_back(cur_seq);
        return;
    }
    while (cur <= n)
    {
        cur_seq.push_back(cur);
        cur++;
        solver(n, k, cur, cur_seq);
        cur_seq.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    solver(n, k, 1, {});
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<vector<int>> ans;

    ans = combine(n, k);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}