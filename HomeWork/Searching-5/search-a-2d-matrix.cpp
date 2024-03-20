class Solution {
public:
    bool binarySearch(vector<int>& matrix ,int target){
        int low=0;
        int high=matrix.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[mid]==target){
                return true;
            }
            else if(matrix[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][0]<=target && matrix[i][m-1]>=target){
                return binarySearch(matrix[i],target);
            }
        }
        return false;
    }
};