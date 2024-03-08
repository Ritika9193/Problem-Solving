class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        int mini=nums[0];
        while(l<=h){
            int mid=(l+h)/2;
            mini=min(min(mini,nums[l]),nums[mid]);
            if(nums[mid]>=nums[l]){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return mini;
    }
};