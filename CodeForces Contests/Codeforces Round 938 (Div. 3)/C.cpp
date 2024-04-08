// GIVES WRONG ANSWER
#include <bits/stdc++.h>

using namespace std;

int solver(int n, float k, vector<int> &nums)
{
    int leftAttacks = ceil(k / 2);
    int rightAttacks = floor(k / 2);
    int ans = 0;
    int i = 0;
    while (i < nums.size() && leftAttacks > 0)
    {
        int t = leftAttacks;
        leftAttacks -= nums[i];
        if (leftAttacks < 0)
        {
            nums[i] -= t;
            break;
        }
        i++;
        ans++;
    }
    int j = nums.size() - 1;
    while (j >= i && rightAttacks > 0)
    {
        rightAttacks -= nums[j];
        if (rightAttacks < 0)
            break;
        j--;
        ans++;
    }
    return ans;

    /* GIVES TLE (1 ≤ k ≤ 10^15, 1 ≤ ai ≤ 10^9)

        int s = 0, e = nums.size() - 1;
        int ans = 0;
        bool attackFirstShip = true;
        while (n && k)
        {
            if (attackFirstShip)
            {
                nums[s] -= 1;
                if (nums[s] == 0)
                {
                    s++;
                    n--;
                    ans++;
                }
            }
            else
            {
                nums[e] -= 1;
                if (nums[e] == 0)
                {
                    e--;
                    n--;
                    ans++;
                }
            }
            attackFirstShip = (!attackFirstShip);
            k--;
        }
        return ans;

    */
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        cout << solver(n, (float)k, nums) << endl;
    }
    return 0;
}