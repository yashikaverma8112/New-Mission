//https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

class Solution {
  public:
  
    bool check(vector<int> &arr, int k, int mid){
        int maxe=0;
        int cnt = 1;
        for(auto ele : arr){
            if(maxe+ele <= mid){
                maxe += ele;
            }
            else{
                cnt++;
                maxe = ele;
            }
        }
        
        return (cnt <= k);
    }
  
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        if(n<k){
            return -1;
        }
        
        int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        
        int ans = -1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(check(arr,k,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    } 
};
