// Problem : https://leetcode.com/problems/power-of-two/
// 👉🏼 this is a much better solution than iteration
#include <bits/stdc++.h>

using namespace std;

bool isPowerOfTwo(int n)
{
    return n <= 0 ? false : !(n & n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << (isPowerOfTwo(n) ? "true" : "false") << endl;
    return 0;
}
