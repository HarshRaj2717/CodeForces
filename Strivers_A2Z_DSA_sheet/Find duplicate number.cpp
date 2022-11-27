// Problem : https://leetcode.com/problems/find-the-duplicate-number/

#include<bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int>& nums) {
    for(int i=0; i<nums.size(); i++) {
        int temp = abs(nums[i]) - 1;
        if(nums[temp] < 0) return abs(nums[i]);
        nums[temp] *= -1;
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << findDuplicate(nums) << endl;

    return 0;
}