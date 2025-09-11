// https://www.geeksforgeeks.org/problems/unsorted-array4925/1

class Solution {
  public:
    int findElement(vector<int> &arr) {
        int n = arr.size();
        
        vector<int>prefix(n);
        vector<int>postfix(n);
        
        prefix[0] = -1;
        postfix[n-1]=-1;
        int maxi = arr[0];
        for(int i=1; i<n; i++){
            maxi = max(maxi,arr[i]);
            prefix[i] = maxi;
        }
        
        int mini = arr[n-1];
        for(int i=n-2; i>=0; i--){
            mini = min(mini,arr[i]);
            postfix[i] = mini;
        }
        
        for(int i=0; i<n; i++){
            if(prefix[i]==postfix[i]){
                return arr[i];
            }
        }
        return -1;
    }
};
