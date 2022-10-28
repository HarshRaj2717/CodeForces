#include<bits/stdc++.h>

using namespace std;

void swapper(int arr[], int i, int j){
    int t=arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

void reverser(int arr[], int s,int e){
    if(s<e){
        swapper(arr, s, e);
        reverser(arr, s+1, e-1);
    }
}

int main(){
    int l;
    cin >> l;
    int arr[l];
    for(int i=0; i<l; i++){
        cin >> arr[i];
    }
    reverser(arr, 0, l-1);
    for(int i=0; i<l; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}