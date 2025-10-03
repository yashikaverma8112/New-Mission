//https://www.geeksforgeeks.org/problems/sort-the-given-array-after-applying-the-given-equation0304/1

class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        for(int i=0; i<arr.size();i++){
            arr[i] = A*arr[i] * arr[i] + B*arr[i] + C;
        }
        sort(arr.begin(),arr.end());
        return arr;
    }
};
