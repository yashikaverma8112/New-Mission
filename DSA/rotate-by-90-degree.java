// https://www.geeksforgeeks.org/problems/rotate-by-90-degree0356/1

class GFG {
  
    
    static void rotate(int mat[][]) {
        // Code Here
        int n = mat.length;
        int m = mat[0].length;
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<m; j++){
                int temp = mat[i][j];
               mat[i][j] = mat[j][i];
               mat[j][i] = temp;
            }
        }
        
        int i = 0;
        int j = m-1;
        
        while(i<j){
            for(int row=0; row<n; row++){
                int temp = mat[row][i];
                mat[row][i] = mat[row][j];
                mat[row][j] = temp;
            }
            i++;
            j--;
        }
    }
}
