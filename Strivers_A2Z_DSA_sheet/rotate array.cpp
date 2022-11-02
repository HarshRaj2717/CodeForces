// Problem : https://leetcode.com/problems/rotate-array/

#include<bits/stdc++.h>

using namespace std;

///////////////////////////////////////////////////////////////
// Solution-1
// Time complexity = O(n)
// Space complexity = O(n)
/*
void rotater(vector<int>& nums, int k){
    int temp[nums.size()];
    for(int i=0; i<nums.size(); i++){
        temp[(i+k)%nums.size()] = nums[i];
    }
    for(int i=0; i<nums.size(); i++){
        nums[i] = temp[i];
    }
}
*/

///////////////////////////////////////////////////////////////
// Solution-1
// Time complexity = O(n)
// Space complexity = O(1)
void rotater(vector<int>& nums, int k){
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin()+k);
    reverse(nums.begin()+k, nums.end());
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    int k;
    cin >> k;

    rotater(nums,k);

    for(int i=0; i<n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}