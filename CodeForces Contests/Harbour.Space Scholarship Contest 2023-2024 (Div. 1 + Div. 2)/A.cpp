// --------------------------------
// THIS IS NOT THE CORRECT SOLUTION.
// --------------------------------
#include <bits/stdc++.h>

using namespace std;

vector<int> solver(int x, int y, int n)
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
        if (difference_elements_val <= 0) {
            return {};
        }
        difference_elements_count -= 1;
        ans[i] += ans[i - 1] + difference_elements_val + difference_elements_count;
        difference_elements_val -= 1;
    }

    return ans[n - 1] == y ? ans : vector<int>();
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
