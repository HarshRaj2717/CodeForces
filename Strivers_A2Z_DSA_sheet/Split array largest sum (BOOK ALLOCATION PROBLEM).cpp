#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> &nums, int k, int m)
{
    int sum = 0, count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > m)
            return false;
        if (sum + nums[i] <= m)
            sum += nums[i];
        else
        {
            sum = nums[i];
            count++;
        }
    }
    return count < k;
}

int splitArray(vector<int> &nums, int k)
{
    int s = nums[0], e = accumulate(nums.begin(), nums.end(), 0);
    int m = s + (e - s) / 2;
    while (s <= e)
    {
        bool possible = check(nums, k, m);
        if (possible)
            e = m - 1;
        else
            s = m + 1;
        m = s + (e - s) / 2;
    }
    return s;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int k;
    cin >> k;

    cout << splitArray(nums, k);

    return 0;
}