// Problem : https://leetcode.com/problems/next-greater-element-ii/
#include <bits/stdc++.h>

using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    vector<int> ans(nums.size(), -1);
    stack<int> left_element_indexes;

    for (int i = 0; i < nums.size(); i++)
    {
        while (!left_element_indexes.empty() && nums[left_element_indexes.top()] < nums[i])
        {
            ans[left_element_indexes.top()] = nums[i];
            left_element_indexes.pop();
        }
        left_element_indexes.push(i);
    }

    for (int i = 0; !left_element_indexes.empty() && i < nums.size(); i++)
    {
        while (!left_element_indexes.empty() && nums[left_element_indexes.top()] < nums[i])
        {
            ans[left_element_indexes.top()] = nums[i];
            left_element_indexes.pop();
        }
    }

    return ans;
}

int main()
{
    int n1;
    cin >> n1;
    vector<int> nums1(n1, 0);
    for (int i = 0; i < n1; i++)
    {
        cin >> nums1[i];
    }

    vector<int> ans = nextGreaterElements(nums1);

    for (int i : ans)
    {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}