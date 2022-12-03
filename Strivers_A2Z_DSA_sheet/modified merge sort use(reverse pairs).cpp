// Problem : https://leetcode.com/problems/reverse-pairs/

#include<bits/stdc++.h>

using namespace std;

int countt = 0;
void merge(vector<int>& nums, int s, int m, int e){
    int i = s;
    int j = m+1;
    while(i <= m && j<=e){
        if(nums[i] / 2.0 <= nums[j]) i++;
        else{
            countt += m - i + 1;
            j++;
        }
    }
    i = s;
    j = m+1;
    int k = 0;
    vector<int> result(e-s+1);
    while(i<=m && j<=e){
        if(nums[i]<=nums[j]){
            result[k] = nums[i];
            i++;
            k++;
        }
        else{
            result[k] = nums[j];
            j++;
            k++;
        }
    }
    while(i<=m){
        result[k] = nums[i];
        i++;
        k++;
    }
    while(j<=e){
        result[k] = nums[j];
        j++;
        k++;
    }
    for(i = s, k = 0; i<=e; i++, k++){
        nums[i] = result[k];
    }
}
void mergeSort(vector<int>& nums, int s, int e){
    if(s<e){
        int m = s + (e-s)/2;
        mergeSort(nums, s, m);
        mergeSort(nums, m+1, e);
        merge(nums, s, m, e);
    }
}
int reversePairs(vector<int>& nums) {
    mergeSort(nums, 0, nums.size()-1);
    return countt;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int i = 0; i < n; i++) cin >> nums[i];

    cout << reversePairs(nums) << endl;

    return 0;
}