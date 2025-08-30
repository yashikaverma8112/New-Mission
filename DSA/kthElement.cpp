//https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

class Solution {
  public:

// TC - O(n+m)

    // int kthElement(vector<int> &a, vector<int> &b, int k) {
    //     int n=a.size(), m = b.size();
    //     int i=0,j=0;
    //     int ind = 0;
    //     while(i<n && j<m){
    //         if(a[i]<=b[j]){
    //             i++;
    //             ind++;
    //             if(ind==k){
    //                 return a[i-1];
    //             }
    //         }
    //         else{
    //             j++;
    //             ind++;
    //             if(ind==k){
    //                 return b[j-1];
    //             }
    //         }
    //     }
        
        
    //     while(i<n)
    //         {
    //            i++;
    //            ind++;
    //             if(ind==k){
    //                 return a[i-1];
    //             }
    //         }
        
    //     while(j<m)
    //         {
    //             j++;
    //             ind++;
    //             if(ind==k){
    //                 return b[j-1];
    //             }
    //         }
        
    //     return -1;
    // }

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n1 = a.size(), n2 = b.size();

        // Always binary search on the smaller array
        if (n1 > n2) return kthElement(b, a, k);

        int low = max(0, k - n2);
        int high = min(k, n1);

        while (low <= high) {
            int mid1 = (low + high) / 2;   // take mid1 elements from a
            int mid2 = k - mid1;           // take mid2 elements from b

            int l1 = (mid1 > 0) ? a[mid1 - 1] : INT_MIN;
            int l2 = (mid2 > 0) ? b[mid2 - 1] : INT_MIN;

            int r1 = (mid1 < n1) ? a[mid1] : INT_MAX;
            int r2 = (mid2 < n2) ? b[mid2] : INT_MAX;

            if (l2 > r1) {
                // Need more elements from a
                low = mid1 + 1;
            } 
            else if (l1 > r2) {
                // Took too many from a
                high = mid1 - 1;
            } 
            else {
                // Correct partition
                return max(l1, l2);
            }
        }

        return -1; // should never reach here
    }
};
};
