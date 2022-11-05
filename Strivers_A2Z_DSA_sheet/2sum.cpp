// Problem : https://leetcode.com/problems/two-sum/

#include<bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    for(int i=0; i<nums.size(); i++){
        int temp = target - nums[i];
        if(m.count(nums[i])) return {m[nums[i]], i};
        else m[temp] = i;
    }        
    return {};
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    int target;
    cin >> target;

    vector<int> ans = twoSum(nums, target);

    for(auto i:ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}