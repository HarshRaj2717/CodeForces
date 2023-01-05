// Given an array of size n. Print minimum and second minimum. Elements can be identical. Print -1 if not found.
// Similar problem : https://practice.geeksforgeeks.org/problems/find-the-smallest-and-second-smallest-element-in-an-array3226/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

#include<bits/stdc++.h>

using namespace std;

void minimums(vector<int>& nums){
    int n = nums.size();
    if(n == 1){
        cout << nums[0] << endl;
        return;
    }
    int minn=INT_MAX, sec_minn=INT_MAX;

    for(int i=0; i<n; i++){
        if(nums[i] < minn){
            sec_minn = minn;
            minn = nums[i];
        }
        else if(nums[i] < sec_minn && nums[i] != minn){
            sec_minn = nums[i];
        }
    }

    if(sec_minn == INT_MAX) cout << minn << " -1" << endl;
    else cout << minn << " " << sec_minn << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    minimums(nums);

    return 0;
}