#include <bits/stdc++.h>

using namespace std;

int maxFrequency(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int s = 0, e = 0;
    int ans = 1;
    long long cur = 0;
    for (; e < nums.size(); e++)
    {
        cur += nums[e];
        while ((long long)(e - s + 1) * nums[e] - cur > k)
        {
            cur -= nums[s];
            s++;
        }
        ans = max(ans, e - s + 1);
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
    int k;
    cin >> k;

    cout << maxFrequency(nums, k) << endl;

    return 0;
}