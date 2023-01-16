// Problem : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

#include<bits/stdc++.h>

using namespace std;

int findMin(vector<int>& nums) {
    int s = 0, e = nums.size() - 1;
    int m = s + (e - s) / 2;
    while(s < e){
        if(s < m && nums[s] == nums[m]) s++;
        else if(m < e && nums[m] == nums[e]) e--;
        else if((s == m || nums[s] < nums[m]) && (m == e || nums[m] < nums[e])) break;
        else if(nums[s] > nums[m]) e = m;
        else s = m + 1;
        m = s + (e - s) / 2;
    }
    return nums[s];
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << findMin(nums) << endl;

    return 0;
}