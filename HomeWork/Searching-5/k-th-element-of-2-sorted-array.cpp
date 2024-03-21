int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    int i=0;
    int j=0;
    int cnt=1;
    int ans=0;
    while(cnt<=k){
        if(arr1[i]<arr2[j]){
            if(cnt==k){
                ans=arr1[i];
            }
            i++;
            cnt++;
        }
        else{
            if(cnt==k){
                ans=arr2[j];
            }
            j++;
            cnt++;
        }
    }
    return ans;
}