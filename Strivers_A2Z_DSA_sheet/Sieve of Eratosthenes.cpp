// Problem : https://leetcode.com/problems/count-primes/
// Explanation : https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
#include <bits/stdc++.h>

using namespace std;

int countPrimes(int n)
{
    vector<bool> primes(n, true);
    int ans = 0;
    int i = 2;

    for (; i * i < n; i++)
    {
        if (primes[i])
        {
            ++ans;
            for (int j = i * i; j < n; j += i)
            {
                primes[j] = false;
            }
        }
    }

    for (; i < n; i++)
    {
        if (primes[i])
            ++ans;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << countPrimes(n) << endl;

    return 0;
}