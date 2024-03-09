#include<bits/stdc++.h>
using namespace std;
int countRotation(int arr[],int low,int high){
    if (high < low) 
        return 0; 
        
    if (high == low) 
        return low; 
  
    int mid = low + (high - low) / 2; 

    if (mid < high && arr[mid + 1] < arr[mid]) 
        return (mid + 1); 

    if (mid > low && arr[mid] < arr[mid - 1]) 
        return mid; 

    if (arr[high] > arr[mid]) 
        return countRotation(arr, low, mid - 1); 
  
    return countRotation(arr, mid + 1, high); 
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<countRotation(arr,0,n-1);
    return 0;
}