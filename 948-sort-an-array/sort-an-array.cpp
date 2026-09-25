class Solution {
public:
void merge(vector<int>& nums1,vector<int>& nums2,vector<int>& ans){
    int i=0,j=0,k=0;
    int n=nums1.size();
    int m= nums2.size();
    while(i<n && j<m){
        if(nums1[i]<nums2[j]){
            ans[k]=nums1[i];
            k++;
            i++;
        }
        else{
            ans[k]=nums2[j];
            j++;
            k++;
        }
        if(i==n){
            while(j<m){
                ans[k]=nums2[j];
                j++;
                k++;
            }
        }
        if(j==m){
            while(i<n){
                ans[k]=nums1[i];
                k++;
                i++;
            }
        }
    }
    return;
}
void mergesort(vector<int>& nums){
    int n=nums.size();
    if(n<=1) return ;
    int n1=n/2;
    int n2=n-n/2;
    vector<int> arr(n1);
    vector<int> brr(n2);
    for(int i=0;i<n1;i++){
        arr[i]=nums[i];
    }
    for(int i=0;i<n2;i++){
        brr[i]=nums[n1+i];
    }
    mergesort(arr);
    mergesort(brr);
    merge(arr,brr,nums);
}
    vector<int> sortArray(vector<int>& nums) {
         mergesort(nums);
         return nums;
    }
};