// https://www.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1

class Solution {
  public:
    void sortBySetBitCount(int arr[], int n) {
      map<int,vector<int>, greater<int>> map;
      for(int i=0; i<n; i++)
      {
          int j=arr[i];
          int c=0;
           while(j)
           {
             if(j%2==1)
             c++;
              j=j/2;
           }
           map[c].push_back(arr[i]);
      }
      int index=0;
      for (auto kv : map) {
     
        for (auto const &i : kv.second)
            arr[index++]=i;
      
    }
    }
};
