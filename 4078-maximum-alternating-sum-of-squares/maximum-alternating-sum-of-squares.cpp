class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long> ans;
        long long max_sum=0;
        for(int x:nums){
            ans.push_back(1LL*x*x);
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<n;i++){
            if(i<(n)/2){
                max_sum-=ans[i];
            }
            else{
                max_sum+=ans[i];
            }
        }
        return max_sum;
    }
};