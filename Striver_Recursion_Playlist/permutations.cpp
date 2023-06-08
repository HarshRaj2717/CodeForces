// Problem : https://leetcode.com/problems/permutations/
// Explanation: In-Notes + https://youtu.be/f2ic2Rsc9pU
// ** This problem has a non-recusrive solution too and it runs faster & will probably also work if "nums" has duplicate elements

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;

void solver_using_map(vector<int> &nums, int left, vector<int> cur = {}, unordered_map<int, int> m = {})
{
    if (!left)
    {
        ans.push_back(cur);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (m[i])
            continue;
        m[i] = 1;
        cur.push_back(nums[i]);
        solver_using_map(nums, left - 1, cur, m);
        cur.pop_back();
        m[i] = 0;
    }
}

void solver_using_swap(vector<int> nums, int cur_index)
{
    if (cur_index == nums.size() - 1)
    {
        ans.push_back(nums);
        return;
    }
    for (int i = cur_index; i < nums.size(); i++)
    {
        swap(nums[i], nums[cur_index]);
        solver_using_swap(nums, cur_index + 1);
        swap(nums[i], nums[cur_index]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    // solver_using_map(nums, nums.size());
    solver_using_swap(nums, 0); // This has better space complexity.
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

    ans = permute(nums);

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