// Problem : https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=median-in-a-row-wise-sorted-matrix
// Explanation : Available in notes and also https://youtu.be/63fPPOdIr2c

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int no_of_smaller_n_equal(vector<vector<int>> &matrix, int R, int C, int t){
        int total = 0;
        for(auto i:matrix){
            int s = 0;
            int e = i.size() - 1;
            int m = s + (e - s) / 2;
            while(s <= e){
                if(i[m] <= t) s = m + 1;
                else e = m - 1;
                m = s + (e - s) / 2;
            }
            total += s;
        }
        return total;
    }

    int median(vector<vector<int>> &matrix, int R, int C){
        // code here
        int s = 1, e = 2000;
        int m = s + (e - s) / 2;
        while(s <= e){
            int t = no_of_smaller_n_equal(matrix, R, C, m);
            if(t > R * C / 2) e = m - 1;
            else s = m + 1;
            m = s + (e - s) / 2;
        }
        return s;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends