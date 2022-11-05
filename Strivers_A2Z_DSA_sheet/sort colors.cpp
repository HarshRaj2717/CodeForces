// Problem : https://leetcode.com/problems/sort-colors/

#include<bits/stdc++.h>

using namespace std;

void sortColors(vector<int>& nums) {
    int x[3] = {0,0,0};
    for(int i=0; i<nums.size(); i++){
        x[nums[i]]++;
    }
    int i=0;
    for(int j=0; j<3; j++){
        while(x[j]){
            nums[i] = j;
            i++;
            x[j]--;
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    sortColors(nums);

    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}