// Problem : https://leetcode.com/problems/subarray-sum-equals-k/

#include<bits/stdc++.h>

using namespace std;

int subarraySum(vector<int>& nums, int k){
    int count=0;
    for(int i=0; i < nums.size(); i++){
        int j=i, temp=0;
        while(j < nums.size()){
            if(temp + nums[j] == k){
                count++;
            }
            temp += nums[j];
            j++;
        }
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