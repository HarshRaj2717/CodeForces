// Problem : https://leetcode.com/problems/subarray-sum-equals-k/

#include<bits/stdc++.h>

using namespace std;

int subarraySum(vector<int>& nums, int k){
    sort(nums.begin(), nums.end());
    int i=0, count=0;
    while(i < nums.size()){
        int temp=0, j=0;
        while(j < nums.size() && temp + nums[j] <= k){
            if(temp + nums[j] == k){
                count += 1;
            }
            temp += nums[j];
            j++;
        }
        i++;
    }
    return count;
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

    cout << subarraySum(nums, k) << endl;

    return 0;
}