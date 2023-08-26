// Problem : https://codeforces.com/problemset/problem/1097/B
// Explanation : https://www.youtube.com/live/ZwU6wSkepBI?si=KV4MZ3Z4yZVp_F6i&t=4769
#include <bits/stdc++.h>

using namespace std;

// Recursion - TC: O(2 ^ n), SC: O(n) (recursive)
bool solver_recusrion(vector<int> &angles, int i = 0, int cur_angle = 0)
{
    if (i >= angles.size())
        return (cur_angle % 360) == 0;

    // clockwise
    bool res_clock = solver_recusrion(angles, i + 1, cur_angle + angles[i]);
    // anti-clockwise
    bool res_antiClock = solver_recusrion(angles, i + 1, cur_angle - angles[i]);

    return res_clock || res_antiClock;
}

// Bitmasking to generate all power sets - TC: O(n * 2 ^ n), SC: O(1) (iteractive)
bool solver_bitmasking(vector<int> &angles)
{
    for (int i = 0; i < (1 << angles.size()); i++)
    {
        int clock = 0;
        for (int j = 0; j < angles.size(); j++)
        {
            if ((i & (1 << j)) == 0)
                clock -= angles[j];
            else
                clock += angles[j];
        }
        if (clock % 360 == 0)
            return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> angles(n);
    for (int i = 0; i < n; i++)
        cin >> angles[i];

    if (solver_bitmasking(angles))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}