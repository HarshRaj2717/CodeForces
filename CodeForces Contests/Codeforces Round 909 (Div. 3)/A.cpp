#include <bits/stdc++.h>

using namespace std;

bool solver(int n)
{
    return n % 3;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        solver(n) ? cout << "First" : cout << "Second";
        cout << endl;
    }
    return 0;
}