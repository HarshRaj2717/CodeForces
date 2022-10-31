#include<bits/stdc++.h>

using namespace std;

int partitioner(int arr[], int s, int e){
    int pivot=s;
    int i=s, j=e;

    while(i<j){
        while(arr[i] <= arr[pivot] && i <= e){
            i++;
        }
        while(arr[j] > arr[pivot] && j >= s){
            j--;
        }
        if(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = temp;

    return j;
}

void quick_sort(int arr[], int s, int e){
    if(s<e){
        int pivot = partitioner(arr, s, e);
        quick_sort(arr, s, pivot-1);
        quick_sort(arr, pivot+1, e);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    quick_sort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}