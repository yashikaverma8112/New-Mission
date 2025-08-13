https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int n = gas.size();
        int totalgas = 0, totalcost = 0;
        for(int i=0;i<n;i++){
            totalgas += gas[i];
            totalcost += cost[i];
        }
        if(totalcost > totalgas){
            return -1;
        }
        
        int total=0, ans=0;
        
        for(int i=0; i<n; i++){
            total += (gas[i] - cost[i]);
            
            if(total < 0){
                ans = (i+1)%n;
                total = 0;
            }
        }
        return ans;
    }
};
