//https://www.geeksforgeeks.org/problems/sorted-matrix2333/1

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                pq.push(Mat[i][j]);
            }
        }
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                Mat[i][j] = pq.top();
                pq.pop();
            }
        }
        
        return Mat;
    }
};
