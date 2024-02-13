#include <bits/stdc++.h>

using namespace std;

int solver(vector<int> nums)
{
    if (nums.size() < 2)
    {
        return 0;
    }
    int equal_elements = 0;
    if (nums[0] == nums[nums.size() - 1])
    {
        equal_elements += 2;
        int i = 1;
        while (i < nums.size() - 1 && nums[i] == nums[0])
        {
            equal_elements++;
            i++;
        }
        int j = nums.size() - 2;
        while (j > i && nums[j] == nums[0])
        {
            equal_elements++;
            j--;
        }
    }
    else
    {
        int left = 1;
        int right = 1;
        int i = 1;
        while (i < nums.size() - 1 && nums[i] == nums[0])
        {
            left++;
            i++;
        }
        i = nums.size() - 2;
        while (i >= 1 && nums[i] == nums[nums.size() - 1])
        {
            right++;
            i--;
        }
        equal_elements = max(left, right);
    }
    return nums.size() - equal_elements;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        cout << solver(nums) << endl;
    }
    return 0;
}