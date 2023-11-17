#include <bits/stdc++.h>

using namespace std;

bool isSortedAfterIndex(vector<int> &nums, int i)
{
    for (i = i + 1; i < nums.size(); i++)
        if (nums[i - 1] > nums[i])
            return false;
    return true;
}

int solver(vector<int> &nums)
{
    int ans = min_element(nums.begin(), nums.end()) - nums.begin();
    return isSortedAfterIndex(nums, ans) ? ans : -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        cout << solver(nums) << endl;
    }
    return 0;
}