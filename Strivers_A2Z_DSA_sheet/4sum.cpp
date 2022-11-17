// Problem : https://leetcode.com/problems/4sum/

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;
        for(int j = i+1; j < nums.size(); j++){
            if(j > i+1 && nums[j] == nums[j-1]) continue;
            int s = j+1;
            int e = nums.size() - 1;
            long long temp = (long long) target - nums[i] - nums[j];
            while(s<e){
                int sum = nums[s] + nums[e];
                if(sum == temp){
                    vector<int> foo = {nums[i], nums[j], nums[s], nums[e]};
                    ans.push_back(foo);
                    s++;
                    e--;
                    while(s<e && nums[s] == foo[2]) s++;
                    while(s<e && nums[e] == foo[3]) e--;
                }
                else if(sum > temp) e--;
                else s++;
            }
        }
    }
    return ans;
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

    vector<vector<int>> ans = fourSum(nums, target);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}