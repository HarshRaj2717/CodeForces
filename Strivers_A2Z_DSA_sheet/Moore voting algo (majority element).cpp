// Problem : https://leetcode.com/problems/majority-element/
// Majority element occurs > (n/2) times
#include<bits/stdc++.h>

using namespace std;

int majorityElement1(vector<int>& nums) {
    int majority = nums[0];
    int count = 0;
    for(int i:nums){
        if(count == 0) majority = i;
        if(i == majority) count++;
        else count--;
    }
    return majority;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    cout << majorityElement1(nums) << endl;
    
    return 0;
}