#include<bits/stdc++.h>

using namespace std;

void insertion_sort(int arr[], int s, int e){
    if(s>e){
        return;
    }

    int j=s;
    while(j>0 && arr[j-1]>arr[j]){
        int temp = arr[j-1];
        arr[j-1] = arr[j];
        arr[j] = temp;
        j--;
    }

    insertion_sort(arr, s+1, e);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    insertion_sort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}