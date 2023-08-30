#include <bits/stdc++.h>

using namespace std;

// Made during contest
vector<int> solverAttempt1(int x, int y, int n)
{
    vector<int> ans(n, 0);
    ans[0] = x;

    // finding common difference if `ans` was an AP
    int difference_elements_val = (int)((y - x) / (n - 1));
    int difference_elements_count = n - 1;

    // adding the extra offset left in cases where the common difference is not an int
    // and hence some amount is lost during conversion of float to int
    // example: if x = 1, y = 4, n = 3 then common_difference = 1.5
    //          which gets reduced to 1 on conversion to int
    //          and hence the offset in this case becomes 1 via the formula - `y - an`
    //          where  `an` is calculated using AP's n-th term fomula 'an = a + (n-1)d'
    ans[1] += y - (x + ((n - 1) * difference_elements_val));

    if (difference_elements_val == 1 && (ans[1] == 0 || n > 3))
        return {};

    if (difference_elements_val == 1)
    {
        for (int i = 1; i < n; i++)
        {
            ans[i] += ans[i - 1] + 1;
        }
        return ans[n - 1] == y ? ans : vector<int>();
    }

    // calculate all values based on current differences
    // (which is same for all elements or same for all elements after first element if offset was not 0)
    for (int i = 1; i < n; i++)
    {
        if (difference_elements_val <= 0)
        {
            return {};
        }
        difference_elements_count -= 1;
        ans[i] += ans[i - 1] + difference_elements_val + difference_elements_count;
        difference_elements_val -= 1;
    }

    return ans[n - 1] == y ? ans : vector<int>();
}

// Made after contest
vector<int> solver(int x, int y, int n)
{
    // `(n * (n - 1) / 2)` is calculating sum (for edge case) of differences that can be placed in between x & y
    // basically it calculates the sum of all numbers from 1 to (n-1)
    // this sum calculates the sum of differences for edge case as the end case consists of following difference - (n-1), (n-2), (n-3), ..., 3, 2, 1
    // this is occuring because of the way we are running `cur_diff` variable
    // finally we are comparing it with (y-x) which is the available difference between y & x
    // so the statement becomes - "if avaible_difference < least_possible_differnce then return {}"
    if((y - x) < (n * (n - 1) / 2)) return {};

    vector<int> ans(n);
    ans[0] = x;
    ans[n - 1] = y;
    int cur_diff = 1;
    for (int i = n - 2; i >= 1; i--)
    {
        ans[i] = ans[i+1] - cur_diff;
        cur_diff++;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++)
    {
        int x, y, n;
        cin >> x >> y >> n;

        vector<int> ans = solver(x, y, n);

        if (ans.size() == 0)
        {
            cout << -1 << endl;
            continue;
        }
        for (auto i : ans)
        {
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}
