#include <bits/stdc++.h>

using namespace std;

bool solver(int n, int c, int d, vector<int> &nums)
{
    int a11 = *min_element(nums.begin(), nums.end());

    unordered_map<int, int> m;
    for (int i : nums)
        m[i]++;

    vector<vector<int>> mat(n, vector<int>(n));
    mat[0][0] = a11;

    for (int i = 1; i < n; i++)
    {
        mat[0][i] = mat[0][i - 1] + d;
        m[mat[0][i]]--;
        if (m[mat[0][i]] < 0)
            return false;
    }
    for (int i = 1; i < n; i++)
    {
        mat[i][0] = mat[i - 1][0] + c;
        m[mat[i][0]]--;
        if (m[mat[i][0]] < 0)
            return false;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (mat[i][j - 1] + d != mat[i - 1][j] + c)
                return false;

            mat[i][j] = mat[i][j - 1] + d;
            m[mat[i][j]]--;

            if (m[mat[i][j]] < 0)
                return false;
        }
    }

    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c, d;
        cin >> n >> c >> d;
        vector<int> nums(n * n);
        for (int i = 0; i < n * n; i++)
        {
            cin >> nums[i];
        }
        solver(n, c, d, nums) ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}