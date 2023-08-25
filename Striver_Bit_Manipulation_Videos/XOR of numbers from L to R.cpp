// Problem : Return XOR of all number from L to R (inclusive) in O(1) time & space complexity
// Explanation : https://www.youtube.com/live/5rtVTYAk9KQ?si=XRPdo9MWG8vynx_n&t=3149
#include <bits/stdc++.h>

using namespace std;

int xor_1_to_n(int n)
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

int solver(int L, int R)
{
    return xor_1_to_n(L) ^ xor_1_to_n(R) ^ L;
}

int main()
{
    int L, R;
    cin >> L >> R;

    cout << solver(L, R) << endl;

    return 0;
}