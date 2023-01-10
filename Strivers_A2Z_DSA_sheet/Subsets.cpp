// Problem : https://leetcode.com/problems/subsets/description/

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    ans.push_back({});
    for(int i:nums){
        vector<vector<int>> temp=ans;
        for(auto j:temp){
            j.push_back(i);
            ans.push_back(j);
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    vector<vector<int>> ans = subsets(nums);

    for(auto i:ans){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}