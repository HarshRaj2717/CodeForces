#include<bits/stdc++.h>

using namespace std;

void bubble_sort(int arr[], int e){
    if(e==0){
        return;
    }

    int count = 0;
    for(int i=0; i<e; i++){
        if(arr[i+1] < arr[i]){
            // swap(arr[i], arr[i+1]);
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }

    if(count==0){
        return;
    }

    bubble_sort(arr, e-1);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    bubble_sort(arr, n-1);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}