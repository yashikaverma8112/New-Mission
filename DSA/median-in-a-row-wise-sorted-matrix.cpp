// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

class Solution {
  public:
  
    // Counts how many numbers are <= ele in the matrix
    int countSmallerOrEqual(vector<vector<int>> &mat, int ele) {
        int cnt = 0;
        int n = mat.size();
        
        for(int i=0; i<n; i++) {
            int s = 0, e = mat[i].size() - 1;
            
            while(s <= e) {
                int mid = s + (e - s) / 2;
                
                if(mat[i][mid] <= ele) {
                    s = mid + 1; // move right
                } else {
                    e = mid - 1; // move left
                }
            }
            cnt += s; // number of elements <= ele in row i
        }
        return cnt;
    }
  
    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        // Find global minimum (first col) and maximum (last col)
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i=0; i<n; i++) {
            mini = min(mini, mat[i][0]);
            maxi = max(maxi, mat[i][m-1]);
        }
        
        int desired = (n * m + 1) / 2; // index of median
        
        while(mini < maxi) {
            int mid = mini + (maxi - mini) / 2;
            int cnt = countSmallerOrEqual(mat, mid);
            
            if(cnt < desired) {
                mini = mid + 1;
            } else {
                maxi = mid;
            }
        }
        return mini; // or maxi, both converge
    }
};
