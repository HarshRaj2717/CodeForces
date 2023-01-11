#include<bits/stdc++.h>

using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int s = 0, e = mat.size() - 1;
    int m = s + (e - s) / 2;
    while(s <= e){
        int maxx = 0;
        for(int i=0; i<mat[m].size(); i++){
            if(mat[m][i] > mat[m][maxx]) maxx = i;
        }
        
        int u = (m > 0 ? mat[m-1][maxx] : -1);
        int d = (m < mat.size() - 1 ? mat[m+1][maxx] : -1);
        if(u < mat[m][maxx] && mat[m][maxx] > d) return {m, maxx};
        else if(u < mat[m][maxx] || mat[m][maxx] < d) s = m + 1;
        else e = m - 1;
        m = s + (e - s) / 2;
    }
    return {-1, -1};
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat;
    for(int i=0; i<n; i++){
        vector<int> temp;
        for(int j=0; j<m; j++){
            int t;
            cin >> t;
            temp.push_back(t);
        }
        mat.push_back(temp);
    }

    vector<int> ans = findPeakGrid(mat);

    for(int i:ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}