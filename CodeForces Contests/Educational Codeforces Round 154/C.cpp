// THIS FAILS ON SOME EDGE CASE
#include <bits/stdc++.h>

using namespace std;

int length = 0;
int last_sort = -1;
int decreasing_order_elements = 0;

bool isSortingCorrect(int askedSorting)
{
    if (length < 2)
        return askedSorting == 1;
    if (last_sort == 0 && askedSorting == 1 && decreasing_order_elements != 0)
        return false;
    last_sort = askedSorting;
    return true;
}

bool solver(string s)
{
    for (auto i : s)
    {
        if (i == '+')
        {
            length++;
        }
        else if (i == '-')
        {
            length--;
            if (decreasing_order_elements > 0)
                decreasing_order_elements--;
        }
        else
        {
            if (!isSortingCorrect(i - '0'))
                return false;
        }
        if (length < 2)
            last_sort = -1;
        if ((last_sort == 0 && i == '+') || (i == '0' && decreasing_order_elements == 0))
            decreasing_order_elements++;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        length = 0;
        last_sort = -1;
        string s;
        cin.ignore();
        cin >> s;
        if (solver(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}