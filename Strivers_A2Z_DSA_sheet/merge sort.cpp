#include<bits/stdc++.h>

using namespace std;

void merge(int arr[], int s, int mid, int e){
    int temp[e+1];
    int i=s, j=mid+1, pos=s;

    while(i<mid+1 && j<e+1){
        if(arr[i] < arr[j]){
            temp[pos] = arr[i];
            i++;
            pos++;
        }
        else{
            temp[pos] = arr[j];
            j++;
            pos++;
        }
    }

    while(i<mid+1){
        temp[pos] = arr[i];
        i++;
        pos++;
    }
    
    while(j<e+1){
        temp[pos] = arr[j];
        j++;
        pos++;
    }
    for(int i=s; i<e+1; i++){
        arr[i] = temp[i];
    }
}

void mergesort(int arr[], int s, int e){
    if(s<e){
        int mid = s + (e-s)/2;
        mergesort(arr, s, mid);
        mergesort(arr, mid+1, e);
        merge(arr, s, mid, e);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    mergesort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}