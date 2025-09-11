// https://www.geeksforgeeks.org/problems/reverse-array-in-groups0255/1

class Solution {
  public:
    
    void reverse(vector<int>&arr,int s, int e){
        while(s<e){
            swap(arr[s],arr[e]);
            s++;
            e--;
        }
    }
  
    void reverseInGroups(vector<int> &arr, int k) {
        if(k==0){
            return;
        }
        
        int s = 0; 
        int e = k-1;
        int rounds = arr.size()/k;
        
        for(int i=0; i<rounds;i++){
            reverse(arr,s,e);
            s += k;
            e +=k;
        }
        if(n%k){
            reverse(arr,s,arr.size()-1);
        }
    }
};
