// Problem : https://leetcode.com/problems/single-number-iii/
// Explanation : https://www.youtube.com/live/ZwU6wSkepBI?si=ijGmh5AZpQorlqEo&t=1130
#include <bits/stdc++.h>

using namespace std;

vector<int> singleNumber(vector<int> &nums)
{
    vector<int> ans(2, 0);
    int xor_all = 0;
    for (int i = 0; i < nums.size(); i++)
        xor_all ^= nums[i];

    int last_set_bit;
    // finding the last (right-most) set bit of xor_all
    if (xor_all == INT_MIN)
        last_set_bit = 1;
    else
        last_set_bit = (xor_all & (xor_all - 1)) ^ xor_all;

    for (int i = 0; i < nums.size(); i++)
    {
        if ((nums[i] & last_set_bit) == 0)
            ans[0] ^= nums[i];
        else
            ans[1] ^= nums[i];
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> ans = singleNumber(nums);
    cout << ans[0] << ' ' << ans[1] << endl;

    return 0;
}