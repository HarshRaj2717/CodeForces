// Problem : https://practice.geeksforgeeks.org/problems/count-digits5716/1

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N){
        //code here
        int c = 0, m=N, k;
        while(N){
            k = N%10;
            N = N/10;
            if(k!=0 && m%k==0){
                c++;
            }
        }
        return c;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends