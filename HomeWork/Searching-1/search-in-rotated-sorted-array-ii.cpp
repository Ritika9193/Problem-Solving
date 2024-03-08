class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[s]==nums[mid] && nums[e]==nums[mid]){
                s++;
                e--;
                continue;
            }
            if(nums[s]<=nums[mid]){
                if(nums[s]<=target && target<nums[mid]){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            else{
                if(target<=nums[e] && nums[mid]<target){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
            
        }
        return false;
    }
};