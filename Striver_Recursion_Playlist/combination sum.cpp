// Problem: https://leetcode.com/problems/combination-sum/
// Explanation: In-Notes + https://youtu.be/OyZFFqQtu98

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;

void solver(int i, int cur_target, vector<int> cur_sequence, vector<int> &candidates)
{
    if (cur_target == 0)
    {
        ans.push_back(cur_sequence);
        return;
    }
    if (i >= candidates.size() || cur_target < 0)
        return;

    // not-take
    solver(i + 1, cur_target, cur_sequence, candidates);
    // take
    cur_sequence.push_back(candidates[i]);
    solver(i, cur_target - candidates[i], cur_sequence, candidates);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    solver(0, target, {}, candidates);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> candidates(n);
    for (int i = 0; i < n; i++)
        cin >> candidates[i];
    int target;
    cin >> target;
    vector<vector<int>> ans;

    ans = combinationSum(candidates, target);
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