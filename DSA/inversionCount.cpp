// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1


class Solution {
  public:
  
    int merge(vector<int> &arr, int low , int mid, int high){
        vector<int>temp;
        int cnt = 0;
        
        int left = low;
        int right = mid+1;
        
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                cnt += mid - left + 1;
                right++;
            }
        }
        
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i=low; i<=high; i++){
            arr[i] = temp[i-low];
        }
        
        return cnt;
    }
  
    int mergeSort(vector<int> &arr, int low , int high){
        int cnt = 0;
        int mid = low + (high-low)/2;
        
        if(low >= high){
            return cnt;
        }
        
        cnt += mergeSort(arr,low,mid);
        cnt += mergeSort(arr,mid+1,high);
        cnt += merge(arr,low,mid,high);
        
        return cnt;
    }
  
    int inversionCount(vector<int> &arr) {
       
      /*
      TC - O(n*n)
       for(int i=0; i<arr.size();i++){
           
           for(int j=0; j<arr.size();j++){
               if(i<j && arr[i] > arr[j]){
                   cnt++;
               }
               
           }
       }
       */
       
       return mergeSort(arr,0,arr.size()-1);
    }
};
