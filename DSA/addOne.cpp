// https://www.geeksforgeeks.org/problems/adding-one2529/1

class Solution {
  public:
    vector<int> addOne(vector<int>& arr) {
        // code here
        vector<int>ans;
        int n = arr.size();
        int carry = 1;
        for(int i=n-1; i>=0; i--){
            if(arr[i]+carry <= 9){
                ans.push_back(arr[i]+carry);
                carry = 0;
            }
            else{
                ans.push_back(0);
                carry = 1;
            }
        }
        if(carry == 1){
            ans.push_back(1);
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
