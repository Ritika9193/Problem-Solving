class Solution {
public:
    bool isPossible(vector<int>& bloomDay,int m,int k,int mid){
        int cnt=0;
        int totalcnt=0;
        int n=bloomDay.size();
        for(int i=0;i<n;i++){
            if(mid>=bloomDay[i]){
                cnt++;
                if(cnt==k){
                    totalcnt++;
                    cnt=0;
                }
            }
            else{
                cnt=0;
            }
        }
        return totalcnt>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(m>n/k) return -1;

        int low=1;
        int high=INT_MIN;
        for(int i=0;i<n;i++){
            high=max(high,bloomDay[i]);
        } 
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(bloomDay,m,k,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};