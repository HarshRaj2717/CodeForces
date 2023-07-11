// Problem : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// Explanation : https://youtu.be/bLGZhJlt4y0

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    vector<string> ans;
    string cur;
    vector<vector<bool>> visited;
    int i = 0, j = 0;

    void solver(vector<vector<int>> &m, int &n)
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(cur);
            return;
        }
        if (i < n - 1 && m[i + 1][j] == 1 && !visited[i + 1][j])
        {
            ++i;
            visited[i][j] = true;
            cur.push_back('D');
            solver(m, n);
            cur.pop_back();
            visited[i][j] = false;
            --i;
        }
        if (j > 0 && m[i][j - 1] == 1 && !visited[i][j - 1])
        {
            --j;
            visited[i][j] = true;
            cur.push_back('L');
            solver(m, n);
            cur.pop_back();
            visited[i][j] = false;
            ++j;
        }
        if (j < n - 1 && m[i][j + 1] == 1 && !visited[i][j + 1])
        {
            ++j;
            visited[i][j] = true;
            cur.push_back('R');
            solver(m, n);
            cur.pop_back();
            visited[i][j] = false;
            --j;
        }
        if (i > 0 && m[i - 1][j] == 1 && !visited[i - 1][j])
        {
            --i;
            visited[i][j] = true;
            cur.push_back('U');
            solver(m, n);
            cur.pop_back();
            visited[i][j] = false;
            ++i;
        }
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        if (m[0][0] == 0 || m[n - 1][n - 1] == 0)
            return {};
        // Your code goes here
        visited = vector<vector<bool>>(n, vector<bool>(n, false));
        visited[0][0] = true;
        solver(m, n);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends