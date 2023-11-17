#include <bits/stdc++.h>

using namespace std;

int solver(vector<int> &nums)
{
    int sum = nums[0], ans = nums[0];
    bool prev_was_odd = (sum % 2 != 0);
    for (int i : nums)
    {
        if ((i % 2 != 0) == prev_was_odd)
            sum = i;
        else if (sum < 0)
            sum = i;
        else
            sum += i;
        ans = max(ans, sum);
        prev_was_odd = (i % 2 != 0);
    }
    return ans;
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