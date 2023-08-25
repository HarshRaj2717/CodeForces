// Problem : https://leetcode.com/problems/single-number-ii/
#include <bits/stdc++.h>

using namespace std;

int singleNumber(vector<int> &nums)
{
    int ans = 0;
    int mask = 1;
    for (int _ = 0; _ <= 32; _++) // Running till j == 32 so that the -ve bit also gets checked
    {
        int cur = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if ((nums[i] & mask) == 0)
                continue;
            else
                cur++;
        }
        if ((cur % 3) != 0)
            ans |= mask;
        mask = mask << 1;
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

    cout << singleNumber(nums) << endl;

    return 0;
}