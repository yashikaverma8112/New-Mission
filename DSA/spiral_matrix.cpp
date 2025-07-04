#include<iostream>
#include <vector>
using namespace std;

vector<int>spiralMatrix(vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();
    vector<int>ans;

    int rowBeg = 0, colBeg = 0, rowEnd = n-1, colEnd = m-1;
    int total = n*m;

    int cnt = 0;

    while(cnt < total){
        for(int j=colBeg; j<=colEnd && cnt < total; j++){
            ans.push_back(mat[rowBeg][j]);
            cnt++;
        }
        rowBeg++;

        for(int i=rowBeg; i<=rowEnd && cnt < total; i++){
            ans.push_back(mat[i][colEnd]);
            cnt++;
        }
        colEnd--;

        for(int j=colEnd; j>=colBeg && cnt < total; j--){
            ans.push_back(mat[rowEnd][j]);
            cnt++;
        }
        rowEnd--;

        for(int i=rowEnd; i>=rowBeg && cnt < total; i++ ){
            ans.push_back(mat[i][colBeg]);
            cnt++;
        }
        colBeg++;
    }
    return ans;
}
