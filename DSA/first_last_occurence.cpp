vector<in>first_last_occ(vector<int>&arr, int x){
    vector<int>ans(2,-1);
    int low = 0, high = arr.size()-1;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid]==x){
            ans[0] = mid;
            high = mid-1;

        }
        else if(arr[mid] < x){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    // last occurence

    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==x){
            ans[1]=mid;
            low = mid-1;
        }
        else if(arr[mid]<x){
            low = mid-1;
        }
        else{
            high =  mid+1;
        }
        
    }
    return ans;
}