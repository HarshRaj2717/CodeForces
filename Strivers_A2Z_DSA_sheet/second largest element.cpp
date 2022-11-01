#include<bits/stdc++.h>

using namespace std;

int sec_largest(int arr[], int n){
    int first, second;
    first = second = INT_MIN;
    
    for(int i=0; i<n; i++){
        if(arr[i] > first){
            second = first;
            first = arr[i];
        }
        else if(second < arr[i] && arr[i] < first){
            second = arr[i];
        }
    }
    
    if(second == INT_MIN) return -1;
    return second;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << sec_largest(arr, n) << endl;

    return 0;
}