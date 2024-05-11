class Solution {
private:
    int solve(vector<int>& nums, int start, int end)
    {
        int curr=0, prev=0, temp;
        for(int i=start ; i<=end ; i++)
        {
            temp = curr;
            curr = max(curr, prev+nums[i]);
            prev = temp;
        }
        return curr;
    }
public:
    int rob(vector<int>& nums) {

        if(nums.size()==1)
            return nums[0];

        int ans1 = solve(nums, 0, nums.size()-2);
        int ans2 = solve(nums, 1, nums.size()-1);

        return max(ans1, ans2);
    }
};