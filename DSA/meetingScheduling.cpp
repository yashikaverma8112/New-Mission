
//https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1


bool comp(pair<int,int>a, pair<int,int>b){
    return a.second < b.second;
}


int maxMeeting(vector<int>&start, vector<int>&end){
    int ans = 0;
    vector<pair<int,int>>time;

    for(int i=0; i<start.size(); i++){
        time.push_back({start[i], end[i]});
    }

    sort(time.begin(), time.end(), comp);
    int ending = -1;
    for(int i=0; i<end.size(); i++){
        if(time[i].first > ending){
            ans++;
            ending = time[i].second;
        }
    }
    return ans;
}