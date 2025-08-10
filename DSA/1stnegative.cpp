class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        vector<int>ans;
        
        // for(int i=0; i<arr.size();i++){
        //     for(int j=i; j<k;j++){
        //         if(arr[j] < 0){
        //             ans.push_back(arr[j]);
        //         }
        //         else{
        //             ans.push_back(0);
        //         }
        //     }
        // }
        
        queue<int>q;
        for(int i=0; i<k; i++){
            if(arr[i]<0){
                q.push(i);
            }
        }
        
        if(!q.empty()){
            ans.push_back(arr[q.front()]);
        }
        else{
            ans.push_back(0);
        }
        
        int i = k;
        while(i<arr.size()){
            if(!q.empty() && i-k >= q.front()){
                q.pop();
            }
            if(arr[i] < 0){
                q.push(i);
            }
            
            if(q.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(arr[q.front()]);
            }
            
            i++;
        }
        return ans;
    }
};
