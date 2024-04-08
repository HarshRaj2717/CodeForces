#include <bits/stdc++.h>

using namespace std;

int solver(int n, int a, int b)
{
    return 2 * a > b ? ((n / 2) * b + (n % 2) * a) : (n * a);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        cout << solver(n, a, b) << endl;
    }
    return 0;
}