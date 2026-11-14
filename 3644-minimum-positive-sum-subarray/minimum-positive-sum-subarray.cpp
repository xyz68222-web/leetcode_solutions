class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int mn=INT_MAX;
        for(int i=0;i<n;i=i+1){
            int s=0;
            for(int j=i;j<n && j<i+r ;j++){
                s+=nums[j];
            
                int len=j-i+1;
        
                if(len>=l && len<=r && s>0){
                   mn=min(mn,s);
                }
            }
        }
        if(mn==INT_MAX)
        return -1;
        return mn;
    }
};