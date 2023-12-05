#include <bits/stdc++.h>

using namespace std;

void solver(char x, int y)
{
    for (char i = 'a'; i <= 'h'; i++)
    {
        if (i == x)
            continue;
        cout << i << y << endl;
    }
    for (int i = 1; i <= 8; i++)
    {
        if (i == y)
        {
            continue;
        }
        cout << x << i << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string temp;
        cin >> temp;
        solver(temp[0], (temp[1] - '0'));
    }
    return 0;
}