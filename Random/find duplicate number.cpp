// Problem : https://leetcode.com/problems/find-the-duplicate-number/description/
// Using bit-manipulation in time O(n), space O(1) and without modifying array

#include <bits/stdc++.h>

using namespace std;


int findDuplicate(vector<int>& nums) {
    int ans = 0;
    for(int i = 0; i < 21; i++){
        int temp = 1 << i;
        if(temp > nums.size()) break;

        int actual = 0;
        int expected = 0;
        for(int j = 0; j < nums.size(); j++){
            // actual number of 1s
            if(nums[j] & temp) actual++;
            // expected number of 1s
            if(j & temp) expected++;
        }
        if(actual > expected) ans += temp;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i]; 
    }

    cout << findDuplicate(nums);

    return 0;
}