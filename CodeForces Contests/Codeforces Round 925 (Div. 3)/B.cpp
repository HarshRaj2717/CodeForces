#include <bits/stdc++.h>

using namespace std;

int check(vector<int> &nums, int matcher)
{
    if (matcher < 0)
        return -1;
    int left_over = 0;
    for (int i : nums)
    {
        left_over += max(0, i - matcher);
        if (i < matcher)
        {
            left_over -= (matcher - i);
            if (left_over < 0)
            {
                return left_over;
            }
        }
    }
    return left_over;
}

bool solver(vector<int> nums)
{
    int s = 0;
    int e = *max_element(nums.begin(), nums.end());
    int m = s + (e - s) / 2;
    int cur_left_over = -1;
    while (s <= e)
    {
        cur_left_over = check(nums, m);
        if (cur_left_over == 0)
        {
            return true;
        }
        else if (cur_left_over > 0)
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
        m = s + (e - s) / 2;
    }
    cur_left_over = check(nums, s);
    return cur_left_over == 0;
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
        solver(nums) ? cout << "YES" : cout << "NO";
        cout << endl;
    }
    return 0;
}