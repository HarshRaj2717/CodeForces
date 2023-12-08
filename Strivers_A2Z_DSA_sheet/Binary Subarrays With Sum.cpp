// Problem : https://leetcode.com/problems/binary-subarrays-with-sum/
#include <bits/stdc++.h>

using namespace std;

int atMostK(vector<int> &nums, int goal)
{
    if (goal < 0)
        return 0;
    int ans = 0;
    int s = 0, e = 1;
    int cur_sum = nums[0];
    while (e <= nums.size())
    {
        if (cur_sum <= goal)
        {
            ans += (e - s);
            cur_sum += nums[e];
            e++;
        }
        else
        {
            cur_sum -= nums[s];
            s++;
        }
    }
    cout << ans << ' ';
    return ans;
}
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    return atMostK(nums, goal) - atMostK(nums, goal - 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int goal;
    cin >> goal;
    cout << numSubarraysWithSum(nums, goal);
    return 0;
}