// Problem : https://leetcode.com/problems/trapping-rain-water/
// Explanation : https://youtu.be/m18Hntz4go8?si=6IRIpw5Qqyd0Gs57

#include <bits/stdc++.h>

using namespace std;

int trap(vector<int> &height)
{
    // This isn't the most optimized approach (check the explanation video)
    int ans = 0;
    vector<int> leftMax(height.size(), 0);
    vector<int> rightMax(height.size(), 0);
    leftMax[0] = height[0];
    rightMax[height.size() - 1] = height[height.size() - 1];

    for (int i = 1; i < height.size(); i++)
    {
        leftMax[i] = max(leftMax[i - 1], height[i]);
        rightMax[height.size() - i - 1] = max(rightMax[height.size() - i], height[height.size() - i - 1]);
    }

    for (int i = 0; i < height.size() - 1; i++)
    {
        ans += max(0, min(leftMax[i], rightMax[i]) - height[i]);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> height(n, 0);
    for (int i = 0; i < n; i++)
        cin >> height[i];

    cout << trap(height) << endl;

    return 0;
}