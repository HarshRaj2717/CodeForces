// Problem: https://leetcode.com/problems/subsets/
// Explanation: https://youtu.be/eQCS_v3bw0Q

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;

void solver(vector<int> &nums, int i = 0, vector<int> cur_subset = {})
{
    if (i >= nums.size())
    {
        ans.push_back(cur_subset);
        return;
    }

    solver(nums, i + 1, cur_subset);
    cur_subset.push_back(nums[i]);
    solver(nums, i + 1, cur_subset);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    solver(nums);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<vector<int>> ans;

    ans = subsets(nums);
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