class Solution {
  public:
// TC - O((n+m) log(n+m))
    double medianOf2(vector<int>& a, vector<int>& b) {
            vector<int>temp(a);
            
            double median ;
            
            for(int i=0; i<b.size();i++){
                temp.push_back(b[i]);
            }
            
            sort(temp.begin(),temp.end());
            
            int n = temp.size();
            cout<<n<<" ";
            if(n%2){
                median = temp[(n+1)/2 -1];
                cout<<"odd";
            }
            else{
                median = (temp[n/2 -1] + temp[n/2])/2;
                cout<<"even";
            }
            return median;
    }

// TC - O(n+m)

class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
      
      	// m1 to store the middle element
      	// m2 to store the second middle element
        int m1 = -1, m2 = -1;
    
        // loop till (m+n)/2
        for (int count = 0; count <= (m + n)/2; count++){
            m2 = m1;
          
         	// if both the arrays have remaining elements
            if (i != n && j != m)
                m1 = (a[i] > b[j]) ? b[j++] : a[i++];
            
          	// if only a[] has remaining elements
          	else if (i < n) 
                m1 = a[i++];
          
          	// if only b[] has remaining elements
            else 
                m1 = b[j++];
        }
    
        // return median based on odd/even size
        if ((m + n) % 2 == 1) 
            return m1;
        else
            return (m1 + m2) / 2.0;
    }
};


class Solution {
  public:
   double medianOf2(vector<int> &a, vector<int> &b) {
       
       // TC : O((log(min(m,n))))
    int n = a.size(), m = b.size();
	
  	// if a[] has more elements, then call medianOf2 
  	// with reversed parameters
    if (n > m)
        return medianOf2(b, a);
  
    int lo = 0, hi = n;
    while (lo <= hi) {
        int mid1 = (lo + hi) / 2;
        int mid2 = (n + m + 1) / 2 - mid1;

        // find elements to the left and right of 
        // partition in a[]
        int l1 = (mid1 == 0 ? INT_MIN : a[mid1 - 1]);
        int r1 = (mid1 == n ? INT_MAX : a[mid1]);

        // find elements to the left and right of 
        // partition in b[]
        int l2 = (mid2 == 0 ? INT_MIN : b[mid2 - 1]);
        int r2 = (mid2 == m ? INT_MAX : b[mid2]);

        // if it is a valid partition
        if (l1 <= r2 && l2 <= r1) {
          
          	// if the total elements are even, then median is 
          	// the average of two middle elements
            if ((n + m) % 2 == 0)
                return (max(l1, l2) + min(r1, r2)) / 2.0;
          
          	// if the total elements are odd, then median is 
         	// the middle element
            else
                return max(l1, l2);
        }

        // check if we need to take lesser elements from a[]
        if (l1 > r2){
            hi = mid1 - 1;
        }
        // check if we need to take more elements from a[]
        else{
            lo = mid1 + 1;
        }
    }
    return 0;
}
};
};
