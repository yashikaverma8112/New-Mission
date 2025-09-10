// https://www.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/1

class Solution {
  public:
    void rearrange(vector<int>& arr) {
        int n = arr.size();
        int maxi = arr[n-1] + 1;
        int end = n-1;
        int start = 0;
        for(int i=0; i<n; i++){
            if(i%2==0){
                arr[i] += (arr[end]%maxi) * maxi;
                end--;
            }
            else {
                arr[i] += (arr[start]%maxi) * maxi;
                start++;
            }
        }
        for(int i=0; i<n; i++){
            arr[i] /=maxi;
        }
    }
};
