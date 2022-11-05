// Problem : https://leetcode.com/problems/maximum-subarray/

#include<bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int max = nums[0], sum = 0;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        if(sum > max) max = sum;
        if(sum < 0) sum = 0;
    }
    return max;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    cout << maxSubArray(nums) << endl;
    
    return 0;
}