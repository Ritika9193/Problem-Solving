class Solution {
public:
    bool isPossible(int numStalls, int numCows, vector<int> &stalls,int minDist){
        int lastPlacedCow=stalls[0];
        int totalCowPlaced=1;
        for(int i=1;i<numStalls;i++){
            if(stalls[i]-lastPlacedCow>=minDist){
                totalCowPlaced++;
                lastPlacedCow=stalls[i];
            }
        }
        return totalCowPlaced>=numCows;
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=stalls[n-1]-stalls[0]+1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(n,k,stalls,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};