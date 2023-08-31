// Problem : https://leetcode.com/problems/repeated-dna-sequences/
// Explanation : https://leetcode.com/problems/repeated-dna-sequences/solutions/53952/20-ms-solution-c-with-explanation/
#include <bits/stdc++.h>

using namespace std;

int makeHash(char c)
{
    switch (c)
    {
    case 'A':
        return 0;
    case 'C':
        return 1;
    case 'G':
        return 2;
    case 'T':
        return 3;
    }
    return -1;
}

vector<string> findRepeatedDnaSequences(string s)
{
    // solving this by simply making a unordered_map<string, int> is easy
    // but in interviews, hashmaps aren't very welcomed
    // and the following bit manipulation approach is also faster
    if (s.size() < 10)
        return {};
    vector<string> ans;
    vector<bool> m1((1 << 20), false);
    vector<bool> m2((1 << 20), false);

    int i = 0;
    int value = 0;
    int mask = (1 << 20) - 1;
    for (; i < 10; i++)
    {
        value = ((value << 2) | makeHash(s[i]));
    }
    m1[value] = true;
    for (; i < s.size(); i++)
    {
        value = (((value << 2) & mask) | makeHash(s[i]));
        if (m2[value])
            continue;
        if (m1[value])
        {
            m2[value] = true;
            ans.push_back(s.substr((i - 10 + 1), 10));
        }
        else
        {
            m1[value] = true;
        }
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;

    vector<string> ans = findRepeatedDnaSequences(s);

    for (auto i : ans)
    {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}