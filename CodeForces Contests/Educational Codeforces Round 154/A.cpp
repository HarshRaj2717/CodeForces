#include <bits/stdc++.h>

using namespace std;

int solver(int n)
{
    while(n) {
        if(n % 10 == 3) return 13;
        else if (n % 10 == 1) return 31;
        n /= 10;
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << solver(n) << endl;
    }

    return 0;
}