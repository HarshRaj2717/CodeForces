// Problem : https://leetcode.com/problems/next-greater-element-i/
// Extras : Check line-28 & line-31
#include <bits/stdc++.h>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    stack<int> left_elements; // will use this as a monotonic stack
    unordered_map<int, int> m;

    for (int i : nums2)
    {
        if (!left_elements.empty())
        {
            while (!left_elements.empty() && left_elements.top() < i)
            {
                m[left_elements.top()] = i;
                left_elements.pop();
            }
        }
        left_elements.push(i);
    }

    for (int i : nums1)
    {
        unordered_map<int, int>::iterator temp = m.find(i); // or just write `auto temp = m.find(i)`
        if (temp != m.end())
        {
            ans.push_back(temp->second);
        }
        else
        {
            ans.push_back(-1);
        }
    }

    return ans;
}

int main()
{
    int n1, n2;
    cin >> n1;
    vector<int> nums1(n1, 0);
    for (int i = 0; i < n1; i++)
    {
        cin >> nums1[i];
    }
    cin >> n2;
    vector<int> nums2(n2, 0);
    for (int i = 0; i < n2; i++)
    {
        cin >> nums2[i];
    }

    vector<int> ans = nextGreaterElement(nums1, nums2);

    for (int i : ans)
    {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}