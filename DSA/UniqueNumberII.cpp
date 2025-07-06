
https://www.geeksforgeeks.org/problems/finding-the-numbers0215/1

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        
        // Approach 1
        /*
        
        map<int,int>mp;
        vector<int>ans;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        
        for(auto it =mp.begin(); it != mp.end(); it++){
            if(it->second==1){
                ans.push_back(it->first);
            }
        }
        return ans;
        */
        
        
        // Approach 2 using xor
        
        int xorr = 0;
        int n = arr.size();
        vector<int>ans;
        
        for(int i=0; i<n; i++){
            xorr ^= arr[i];
        }
        
        int num = xorr & -xorr;
        int zero =0, nonzero=0;
        for(int i=0; i<n; i++){
            if(arr[i]&num){
                nonzero ^= arr[i];
            }
            else{
                zero ^= arr[i];
            }
        }
        
        if(zero < nonzero){
            ans.push_back(zero);
            ans.push_back(nonzero);
        }
        else{
            ans.push_back(nonzero);
            ans.push_back(zero);
            
        }
        return ans;
        
    }
};
