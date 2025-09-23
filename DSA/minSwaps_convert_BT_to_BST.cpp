// https://www.geeksforgeeks.org/problems/minimum-swap-required-to-convert-binary-tree-to-binary-search-tree/1
class Solution {
  public:
  
    vector<int>in;
    
    void inorder(vector<int>&arr, int i){
        if(i >= arr.size()){
            return;
        }
        inorder(arr,2*i+1);
        in.push_back(arr[i]);
        inorder(arr,2*i+2);
    }
    
    int minSwaps(vector<int>& arr) {
        inorder(arr,0);
        vector<pair<int,int>>v;
        
        for(int i=0; i<arr.size();i++){
            v.push_back({in[i],i});
        }
        sort(v.begin(),v.end());
        int ans = 0;
        for(int i=0; i<arr.size();i++){
            if(i!= v[i].second){
                swap(v[i],v[v[i].second]);
                i--;
                ans++;
            }
        }
        return ans;
    }
};
