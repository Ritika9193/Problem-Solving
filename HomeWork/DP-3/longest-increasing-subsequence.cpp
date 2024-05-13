class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        
        vector<int> next(n+1, 0);

        for(int i = n-1 ; i >= 0; i--){

            vector<int> curr(n+1,0);

            for(int j = i; j >= 0; j--){

                int p = 0;
                int nP = next[j];
                if(j==0 || nums[i] > nums[j-1]){
                    p = 1 + next[i+1];
                }
                curr[j] = max(p, nP);
            }
            next = curr;
        }
        return next[0];
    }
};
