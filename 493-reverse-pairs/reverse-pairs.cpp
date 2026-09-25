class Solution {
public:
long long merge(vector<int>& a, vector<int>& b,vector<int>& nums){
    int i=0,j=0,k=0;
    int n=a.size();
    int m=b.size();
    long long count=0;
    for(int i=0;i<n;i++){
        while(j<m && (long long)a[i]>2LL*b[j]){
            j++;
        }
        count+=j;
    }
    i=0;
    
     j=0;
    while(i<n && j<m){
        if(a[i]<b[j]){
            nums[k]=a[i];
            i++;
            k++;
        }
        else{
            nums[k]=b[j];
            j++;
            k++;
        }
        if(i==n){
            while(j<m){
                nums[k]=b[j];
                k++;
                j++;
            }
        }
        if(j==m){
            while(i<n){
                nums[k]=a[i];
                i++;
                k++;
            }
        }
    }
    return count ;
}
long long mergesort(vector<int>& ans){
    int n=ans.size();
    if(n<=1) return 0;
    int n1=n/2;
    int n2=n-n1;
    long long count=0;
    vector<int> arr(n1);
    vector<int> brr(n2);
    for(int i=0;i<n1;i++){
        arr[i]=ans[i];
    }
    for(int i=0;i<n2;i++){
        brr[i]=ans[n1+i];
    }
    count+=mergesort(arr);
   count+= mergesort(brr);
   count+= merge(arr,brr,ans);
   return count;
}
    int reversePairs(vector<int>& nums) {
        return (int)mergesort(nums);
    }
};