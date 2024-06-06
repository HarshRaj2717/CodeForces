#include <bits/stdc++.h>

using namespace std;

int solver(vector<int> &nums)
{
    int minn = INT_MAX;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        minn = min(minn, max(nums[i], nums[i + 1]));
    }

    return minn - 1;
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