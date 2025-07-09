https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1


// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        if(n==1)
        {
            return 0;
        }
        sort(arr.begin(), arr.end());
        
        int ans = arr[n-1] - arr[0];
        int largest = arr[n-1] - k;
        int smallest = arr[0] + k;
        
        
        for(int i=0; i<n-1; i++){
           int mini = min(smallest, arr[i+1]-k);
            int maxi = max(largest, arr[i]+k);
            
            if(mini < 0)
            {
                continue;
            }
            
            ans = min(ans,maxi-mini);
        }
        return ans;
    }
};
