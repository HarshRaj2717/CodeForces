// Problem : https://leetcode.com/problems/maximum-product-subarray/

#include<bits/stdc++.h>

using namespace std;

int maxProduct(vector<int>& nums) {
    int maxx = 1, minn = 1;
    int ans = INT_MIN;
    for(int i:nums){
        if(i == 0){
            maxx = 1;
            minn = 1;
        }
        if(i < 0){
            swap(maxx, minn);
        }
        maxx = max(maxx * i, i);
        minn = min(minn * i, i);
        ans = max(maxx, ans);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << maxProduct(nums) << endl;

    return 0;
}