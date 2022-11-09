// Problem : https://leetcode.com/problems/rotate-image/

#include<bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
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

    rotate(matrix);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}