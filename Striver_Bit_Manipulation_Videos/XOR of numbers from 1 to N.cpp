// Problem : Return XOR of all number from 1 to N (inclusive) in O(1) time & space complexity
// Explanation : https://www.youtube.com/live/5rtVTYAk9KQ?si=RTRKLdgCv2XwLQ8b&t=2684
#include <bits/stdc++.h>

using namespace std;

int solver(int n)
{
    switch (n % 4)
    {
    case 0:
        return n;
        break;
    case 1:
        return 1;
        break;
    case 2:
        return n + 1;
        break;
    case 3:
        return 0;
        break;
    }
    return -1; // this line is unreachable, wrote it just to remove the compilation warning
}

int main()
{
    int n;
    cin >> n;

    cout << solver(n) << endl;

    return 0;
}