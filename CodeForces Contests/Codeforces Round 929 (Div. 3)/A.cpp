#include <bits/stdc++.h>

using namespace std;

int solver(vector<int> &nums)
{
    return accumulate(nums.begin(), nums.end(), 0);
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
            int temp;
            cin >> temp;
            nums[i] = abs(temp);
        }
        cout << solver(nums) << endl;
    }
    return 0;
}