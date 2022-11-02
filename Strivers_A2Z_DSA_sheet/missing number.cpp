// Problem : https://leetcode.com/problems/missing-number/

#include<bits/stdc++.h>

using namespace std;

int missing(vector<int>& nums){
    return nums.size() * (nums.size() + 1) / 2 - accumulate(nums.begin(), nums.end(), 0);
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << missing(nums) << endl;

    return 0;
}