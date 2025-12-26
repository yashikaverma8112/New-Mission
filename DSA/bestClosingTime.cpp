class Solution {
public:
    int bestClosingTime(string customers) {
/*
        vector<int>penalty(customers.size()+1,0);
        vector<int>preN(customers.size()+1,0);
        vector<int>suffY(customers.size()+1,0);

        preN[0] = 0;
        suffY[customers.size()] = 0; // 4

        for(int i=1; i<customers.size()+1; i++){
            if(customers[i-1]=='N'){
                preN[i] = preN[i-1] + 1;
            }
            else{
                preN[i] = preN[i-1];
            }
        }
        for(int i=customers.size()-1; i>=0; i--){
           
            if(customers[i]=='Y'){
                suffY[i] = suffY[i+1] + 1;
            }
            else{
                suffY[i] = suffY[i+1];
            }
        }

        for(int i=0;i<customers.size()+1; i++){
            penalty[i] = preN[i] + suffY[i];
            // cout<<preN[i]<<" : "<<suffY[i]<<endl;
        }
        int mini = INT_MAX;
        int j = 0;
        for(int i=0; i<penalty.size(); i++){
            if(mini > penalty[i]){
                mini = penalty[i];
                j=i;
            }
        }
        return j;
        */
        int penalty = 0;
        for(char ch : customers){
            if(ch=='Y'){
                penalty++;
            }
        }
        if(penalty==customers.size() || penalty==0){
            return penalty;
        }
        int bestHour = 0;
        int miniPenalty = penalty;
        for(int i=0; i<customers.size();i++){
            if(customers[i]=='Y'){
                penalty--;
            }
            else{
                penalty++;
            }
            if(miniPenalty > penalty){
                miniPenalty = penalty;
                bestHour = i+1;
            }
        }
        return bestHour;
    }
};
