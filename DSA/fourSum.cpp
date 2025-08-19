https://www.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1

class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &arr, int target) {
        int n = arr.size();
        vector<vector<int>>ans;
        vector<int>temp;
        sort(arr.begin(),arr.end());
        for(int i=0; i<n; i++){
            
            if(i>0 && arr[i]==arr[i-1]) continue;
            
            for(int j = i+1; j<n; j++){
                
                if(j>i+1 && arr[j]==arr[j-1]) continue;
                
                int start = j+1;
                int end = n-1;
                
                while(start < end){
                    int sum = arr[i] + arr[j] + arr[start] + arr[end];
                    
                    if(sum==target){
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[start]);
                        temp.push_back(arr[end]);
                        ans.push_back(temp);
                        temp.clear();
                        start++;
                        end--;
                        
                        while(start<end && arr[start]==arr[start-1]) start++;
                        while(start<end && arr[end]==arr[end+1]) end--;
                        
                    }
                    else if(sum < target){
                        start++;
                    }
                    else{
                        end--;
                    }
                }
            }
        }
        return ans;
    }
};
