// Problem : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

#include<bits/stdc++.h>

using namespace std;

bool search(vector<int>& nums, int target) {
    int s = 0;
    int e = nums.size() - 1;
    int m = s + (e - s) / 2;
    while(s <= e){
        if(nums[m] == target) return true;
        else if(nums[s] == nums[m]){
            while(s <= e && nums[s] == nums[m]) s++;
        }
        else if(nums[e] == nums[m]){
            while(s <= e && nums[e] == nums[m]) e--;
        }
        else if(nums[s] < nums[m]){
            if(nums[s] <= target && target < nums[m]){
                e = m - 1;
            }
            else{
                s = m + 1;
            }
        }
        else{
            if(nums[m] < target && target <= nums[e]){
                s = m + 1;
            }
            else{
                e = m - 1;
            }
        }
        m = s + (e - s) / 2;
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int target;
    cin >> target;

    cout << search(nums, target) << endl;

    return 0;
}