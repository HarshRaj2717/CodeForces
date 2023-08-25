// Problem : You are given 2 integers, swap them using bit manipulation
#include <bits/stdc++.h>

using namespace std;

void swapper(int &a, int &b)
{
    // swap a and b using bit manipulation

    // Method - 3 - works for (-ve) numbers also
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    // Iterative methods - don't work for (-ve) numbers
    int i = 1;
    while (i <= a || i <= b)
    {
        // Method - 1
        // if(((a & i) != 0) && ((b & i) == 0)) {
        //     a = a ^ i;
        //     b = b | i;
        // }
        // else if(((a & i) == 0) && ((b & i) != 0)) {
        //     b = b ^ i;
        //     a = a | i;
        // }

        // Method - 2
        // if((a & i) != (b & i)) {
        //     a ^= i;
        //     b ^= i;
        // }
        i = i << 1;
    }
}

int main()
{
    int a, b;
    cin >> a >> b;

    swapper(a, b);

    cout << a << ' ' << b << endl;
    return 0;
}