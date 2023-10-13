// Problem : https://leetcode.com/problems/find-the-duplicate-number/

#include <bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int> &nums)
{
    // -------------------------------------------
    // visiting each index of the array and setting it to negative just to know if that index has been visited
    // since atleast one element will repeat hence atleast one index will be visited twice
    // -------------------------------------------
    // for(int i=0; i<nums.size(); i++) {
    //     int temp = abs(nums[i]) - 1;
    //     if(nums[temp] < 0) return abs(nums[i]);
    //     nums[temp] *= -1;
    // }
    // return 0;

    // -------------------------------------------
    // Using bit manipulation
    // -------------------------------------------
    int ans = 0;
    for (int i = 0; i < 21; i++)
    {
        int temp = 1 << i;
        if (temp > nums.size())
            break;

        int actual = 0;
        int expected = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            // actual number of 1s
            if (nums[j] & temp)
                actual++;
            // expected number of 1s
            if (j & temp)
                expected++;
        }
        if (actual > expected)
            ans += temp;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << findDuplicate(nums) << endl;

    return 0;
}