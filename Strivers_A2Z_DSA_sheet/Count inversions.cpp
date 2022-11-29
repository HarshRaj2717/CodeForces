// Problem : https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=inversion-of-array

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    long long int count = 0;

    void merge(long long arr[], long long s, long long m, long long e) {
        long long i=s, j=m+1;
        long long temp[e+1];
        int k = s;
        while(i<=m && j<=e){
            if(arr[i] > arr[j]){
                temp[k] = arr[j];
                j++;
                k++;
                count += m - i + 1;
            }
            else{
                temp[k] = arr[i];
                k++;
                i++;
            }
        }
        while(i<=m){
            temp[k] = arr[i];
            k++;
            i++;
        }
        while(j<=e){
            temp[k] = arr[j];
            k++;
            j++;
        }
        for(long long it = s; it < e+1; it++){
            arr[it] = temp[it];
        }
    }

    void mergeSort(long long arr[], long long s, long long e) {
        if(s>=e) return;
        long long m = s + (e-s)/2;
        mergeSort(arr, s, m);
        mergeSort(arr, m+1, e);
        merge(arr,s,m,e);
    }

    long long int inversionCount(long long arr[], long long N) {
        // Your Code Here
        mergeSort(arr,0,N-1);
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends