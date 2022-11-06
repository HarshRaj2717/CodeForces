// Problem : https://leetcode.com/problems/next-permutation/

#include<bits/stdc++.h>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int i, j, check=0;
    for(i=nums.size()-1; i > 0; i--){
        if(nums[i] > nums[i-1]){
            i--;
            check = 1;
            break;
        }
    }
    if(!check){
        reverse(nums.begin(), nums.end());
    }
    else{
        for(j=nums.size()-1; j>i+1; j--){
            if(nums[j-1] > nums[i]){
                j--;
                break;
            }
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin()+i+1, nums.end());
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    nextPermutation(nums);

    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}