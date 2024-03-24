// Problem : https://leetcode.com/problems/most-frequent-ids/

#include <bits/stdc++.h>

using namespace std;

vector<long long> mostFrequentIDs(vector<int> &nums, vector<int> &freq)
{
    vector<long long> ans(nums.size(), 0);
    map<long long, long long> m;
    set<pair<long long, long long>> s;
    for (int i = 0; i < nums.size(); i++)
    {
        s.erase({m[nums[i]], nums[i]});
        m[nums[i]] += freq[i];
        s.insert({m[nums[i]], nums[i]});
        ans[i] = s.rbegin()->first;
    }
    return ans;
}

int main()
{
    int n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int m;
    vector<int> freq;
    for (int i = 0; i < m; i++)
    {
        cin >> freq[i];
    }
    vector<long long> ans = mostFrequentIDs(nums, freq);
    for (auto i : ans)
    {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}