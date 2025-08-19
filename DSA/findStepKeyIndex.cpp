// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
https://www.geeksforgeeks.org/problems/searching-in-an-array-where-adjacent-differ-by-at-most-k0456/1
class Solution {
  public:
    int findStepKeyIndex(vector<int>& arr, int k, int x) {
        // code here
        int i = 0;
        while(i<arr.size()){
            if(arr[i]==x){
                return i;
            }
            i += max(1,abs(arr[i]-x)/k);
        }
        
        return -1;
}
};
