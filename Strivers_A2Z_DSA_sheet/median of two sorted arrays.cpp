// Problem : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Explanation : https://youtu.be/NTop3VTjmxk

#include<bits/stdc++.h>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // Running the function on smaller array to reduce no. of operations
    if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

    int n1 = nums1.size();
    int n2 = nums2.size();
    int s = 0, e = nums1.size();

    while(s <= e){
        int cut1 = (s + e) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int l1 = (cut1 == 0 ? INT_MIN : nums1[cut1 - 1]);
        int l2 = (cut2 == 0 ? INT_MIN : nums2[cut2 - 1]);

        int r1 = (cut1 == n1 ? INT_MAX : nums1[cut1]);
        int r2 = (cut2 == n2 ? INT_MAX : nums2[cut2]);

        if(l1 <= r2 && l2 <= r1){
            if((n1 + n2) % 2 == 0) return (max(l1, l2) + min(r1, r2)) / 2.0;
            else return max(l1, l2);
        }
        else if(l1 > r2) e = cut1 - 1;
        else s = cut1 + 1;
    }

    return 0.0;
}

int main(){
    int n, m;
    cin >> n;
    vector<int> nums1(n,0);
    for(int i=0; i<n; i++){
        cin >> nums1[i];
    }
    cin >> m;
    vector<int> nums2(m,0);
    for(int i=0; i<m; i++){
        cin >> nums2[i];
    }

    cout << findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}