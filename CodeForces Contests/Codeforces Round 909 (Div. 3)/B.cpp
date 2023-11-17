// THIS GIVES INCORRECT ANSWER
#include <bits/stdc++.h>

using namespace std;

int findMaximalDiff(vector<int> &boxes, int k)
{
    /*
     * k == group sizes aka the number of boxes to be put in each truck
     */
    int max_group_sum = INT_MIN, min_group_sum = INT_MAX;
    for (int i = 0; i < boxes.size(); i += k)
    {
        int cur_sum = 0;
        for (int j = i; j < i + k; j++)
            cur_sum += boxes[j];
        max_group_sum = max(max_group_sum, cur_sum);
        min_group_sum = min(min_group_sum, cur_sum);
    }
    return max_group_sum - min_group_sum;
}

int solver(vector<int> &boxes)
{
    int ans = 0;
    for (int k = 1; k < boxes.size(); k++)
    {
        if (boxes.size() % k != 0)
            continue;
        ans = max(ans, findMaximalDiff(boxes, k));
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> boxes(n);
        for (int i = 0; i < n; i++)
        {
            cin >> boxes[i];
        }
        cout << solver(boxes) << endl;
    }
    return 0;
}