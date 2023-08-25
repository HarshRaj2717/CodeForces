// Problem : Print if a number "n" is even or odd
#include <bits/stdc++.h>

using namespace std;

void oddOrEven(int n)
{
    if ((n & 1) == 0)
        cout << "Even" << endl;
    else
        cout << "odd" << endl;
}

int main()
{
    int n;
    cin >> n;

    oddOrEven(n);

    return 0;
}