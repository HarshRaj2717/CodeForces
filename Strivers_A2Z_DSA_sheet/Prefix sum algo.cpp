// Problem : https://leetcode.com/problems/subarray-sum-equals-k/

#include<bits/stdc++.h>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int count=0;
    int sum = 0;
    unordered_map <int, int> presum;
    for(int i:nums){
        sum += i;
        if(sum == k) count++;
        if(presum[sum - k]) count += presum[sum-k];
        presum[sum]++;
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    int k;
    cin >> k;

    cout << subarraySum(nums, k) << endl;

    return 0;
}