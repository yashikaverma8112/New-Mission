https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1
class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        
        if(arr.size() < 2){
            return false;
        }
        sort(arr.begin(),arr.end());
        
        
        // for(int i=0; i<arr.size(); i++){
        //     int sum = x+arr[i];
            
        //     int start = 0;
        //     int end = arr.size()-1;
            
        //     while(start <= end){
        //         int mid = start + (end - start)/2;
                
        //         if(arr[mid]==sum && mid != i){
        //             return true;
        //         }
        //         else if(arr[mid] <= sum){
        //             start = mid+1;
        //         }
        //         else{
        //             end = mid - 1;
        //         }
        //     }
        // }
        
        int i = 0, j=1;
        
        while(i<arr.size() && j<arr.size()){
            
            if(i!=j && arr[j]-arr[i]==x){
                return true;
            }
            else if(arr[j]-arr[i]<x){
                j++;
            }
            else{
                i++;
            }
        }
        
        return false;
    }
};
