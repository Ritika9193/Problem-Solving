bool isPossible(vector<int>boards,int n,int k,int mid){
    int painters=1;
    int boardsum=0;
    for(int i=0;i<n;i++){
        if(boards[i]+boardsum<=mid){
            boardsum+=boards[i];
        }
        else{
            painters++;
            if(painters>k || boards[i]>mid){
                return false;
            }
            boardsum=boards[i];
        }
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int low=0;
    int sum=0;
    int n=boards.size();
    for(int i=0;i<n;i++){
        sum+=boards[i];
    }
    int high=sum;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(isPossible(boards,n,k,mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}