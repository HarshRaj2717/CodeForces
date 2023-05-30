// Problem : https://leetcode.com/problems/longest-common-subsequence/
// Explanation: In Notes

#include <bits/stdc++.h>

using namespace std;

int using_recursion(string &text1, string &text2, int i, int j)
{
    if (!i || !j)
        return 0;
    if (text1[i - 1] == text2[j - 1])
        return 1 + using_recursion(text1, text2, i - 1, j - 1);
    else
        return max(using_recursion(text1, text2, i, j - 1), using_recursion(text1, text2, i - 1, j));
}

int using_DP_memorization(string &text1, string &text2, int i, int j, vector<vector<int>> &mem)
{
    if (mem[i][j] != -1)
        return mem[i][j];
    if (!i || !j)
        mem[i][j] = 0;
    else if (text1[i - 1] == text2[j - 1])
        mem[i][j] = 1 + using_DP_memorization(text1, text2, i - 1, j - 1, mem);
    else
        mem[i][j] = max(using_DP_memorization(text1, text2, i, j - 1, mem), using_DP_memorization(text1, text2, i - 1, j, mem));
    return mem[i][j];
}

int using_DP_tabulation(string &text1, string &text2)
{
    vector<vector<int>> table(text1.size() + 1, vector<int>(text2.size() + 1, -1));
    for (int i = 0; i <= text1.size(); i++)
        table[i][0] = 0;
    for (int j = 0; j <= text2.size(); j++)
        table[0][j] = 0;
    for (int i = 1; i <= text1.size(); i++)
    {
        for (int j = 1; j <= text2.size(); j++)
        {
            if (text1[i - 1] == text2[j - 1])
                table[i][j] = 1 + table[i - 1][j - 1];
            else
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }
    return table[text1.size()][text2.size()];
}

int longestCommonSubsequence(string text1, string text2)
{

    // return using_recursion(text1, text2, text1.size(), text2.size());

    // vector<vector<int>> mem(text1.size()+1, vector<int> (text2.size()+1, -1));
    // return using_DP_memorization(text1, text2, text1.size(), text2.size(), mem);

    return using_DP_tabulation(text1, text2);
}

int main()
{
    string text1, text2;
    cin >> text1;
    cin >> text2;

    cout << longestCommonSubsequence(text1, text2) << endl;

    return 0;
}