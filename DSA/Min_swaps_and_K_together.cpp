// https://www.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1
class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
       int goodEle = 0;    
       for(int i=0; i<arr.size(); i++){
           if(arr[i] <= k){
               goodEle++;
           }
       }
       if(goodEle == 0) return 0;
       
       int winGood=0;
       for(int i=0; i<goodEle; i++){
           if(arr[i] <= k){
               winGood++;
           }
       }
       
       int swaps = goodEle - winGood;
       int i = goodEle;
       while(i<arr.size()){
           if(arr[i-goodEle]<=k){
               winGood--;
           }
           if(arr[i] <= k){
               winGood++;
           }
           swaps = min(swaps, goodEle-winGood);
           i++;
       }
       
       return swaps;
    }
};
