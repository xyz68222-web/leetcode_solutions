class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 0;
        sort(nums.begin(),nums.end());
        int mx=0;
        for(int i=0;i<n-1;i++){
           int diff=(nums[i+1]-nums[i]);
             if(mx<diff){
                mx=diff;
             }
        }
        
        return mx;
    }
};