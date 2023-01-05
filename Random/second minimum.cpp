// Given an array of size n. Print minimum and second minimum. Elements can be identical. Print -1 if not found.
// Similar problem : https://practice.geeksforgeeks.org/problems/find-the-smallest-and-second-smallest-element-in-an-array3226/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

#include<bits/stdc++.h>

using namespace std;

void minimums(vector<int>& nums, int n){
    int minn = nums[0], sec_minn = nums[0];

    for(int i=0; i<n; i++){
        if(nums[i] < minn) minn = nums[i];
    }

    if(minn == nums[0]) sec_minn = nums[1];

    for(int i=0; i<n; i++){
        if(nums[i] != minn && nums[i] < sec_minn) sec_minn = nums[i];
    }

    cout << minn << " " << sec_minn << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    minimums(nums, n);

    return 0;
}