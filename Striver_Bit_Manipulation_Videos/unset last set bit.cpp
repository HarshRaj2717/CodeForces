// Problem : unset/remove last set bit of a n in O(1) time & space complexity
// Explanation : https://www.youtube.com/live/5rtVTYAk9KQ?si=pQlg-rouhjjZLmUi&t=4927
// Same logic will be used for "power of 2" question on leetcode
#include <bits/stdc++.h>

using namespace std;

int solver(int n)
{
    return n & (n - 1);
}

int main()
{
    int n;
    cin >> n;

    cout << solver(n) << endl;

    return 0;
}