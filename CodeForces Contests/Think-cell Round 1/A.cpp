#include <bits/stdc++.h>

using namespace std;

int solver(vector<int> &nums)
{
    int ans = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i += 2)
    {
        ans += nums[i];
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
        vector<int> nums(2 * n);
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> nums[i];
        }
        cout << solver(nums) << endl;
    }
    return 0;
}