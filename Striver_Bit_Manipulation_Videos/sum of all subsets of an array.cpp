// Problem : https://leetcode.com/problems/sum-of-all-subset-xor-totals/
// Explanation : https://leetcode.com/problems/sum-of-all-subset-xor-totals/solutions/1211182/one-liner-bitmask/
#include <bits/stdc++.h>

using namespace std;

int subsetXORSum(vector<int> &nums)
{
    int temp = 0;
    for (int i = 0; i < nums.size(); i++)
        temp |= nums[i];
    return temp << (nums.size() - 1); // temp * 2 ^ (n-1)
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << subsetXORSum(nums) << endl;

    return 0;
}