// https://www.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion1638/1
class Solution {
  public:
    void zigZag(vector<int> &arr) {
        int n = arr.size();
        
        for(int i=0; i<n-1; i++){
            if((i%2==0 && arr[i] > arr[i+1]) || (i%2==1 && arr[i] < arr[i+1])){
                swap(arr[i],arr[i+1]);
            }
        }
    }
};
