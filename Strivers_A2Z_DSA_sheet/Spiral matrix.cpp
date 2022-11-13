// Problem : https://leetcode.com/problems/rotate-image/

#include<bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    if(matrix.size() == 0) return ans;
    int rs = 0;
    int re = matrix.size() - 1;
    int cs = 0;
    int ce = matrix[0].size() - 1;
    while(cs<=ce && rs<=re){
        for(int i=cs; i<=ce; i++) ans.push_back(matrix[rs][i]);
        rs++;
        for(int i=rs; i<=re; i++) ans.push_back(matrix[i][ce]);
        ce--;
        for(int i=ce; i>=cs && rs<=re; i--) ans.push_back(matrix[re][i]);
        re--;
        for(int i=re; i>=rs && cs<=ce; i--) ans.push_back(matrix[i][cs]);
        cs++;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> matrix;
    for(int i=0; i<n; i++){
        vector<int> temp;
        for(int j=0; j<n; j++){
            int temp_int;
            cin >> temp_int;
            temp.push_back(temp_int);
        }
        matrix.push_back(temp);
    }

    vector<int> ans = spiralOrder(matrix);

    for(int i=0; i<n*n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}