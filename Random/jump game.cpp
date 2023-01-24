#include<bits/stdc++.h>

using namespace std;

bool canJump(vector<int>& nums) {
    // int i = 0;
    // while(i < nums.size()){
    //     if(nums[i] == 0) return i == nums.size() - 1;
    //     int temp = i;
    //     for(int j = i + 1; j < nums.size() && j <= i + nums[i]; j++){
    //         if(j - i + nums[j] > temp - i + nums[temp]) temp = j;
    //     }
    //     if(temp == i) i += nums[i];
    //     else i = temp;
    // }
    // return true;
    int cur_distance = 0;
    if(nums[0] == 0) return nums.size() == 1;
    for(int i = 0; i < nums.size(); i++){
        if(cur_distance < i) return false;
        cur_distance = max(cur_distance, i + nums[i]);
        if(cur_distance >= nums.size()-1) return true;
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    canJump(nums) ? cout << "True" : cout << "False";
    cout << endl;

    return 0;
}