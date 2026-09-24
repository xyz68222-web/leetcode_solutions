class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int k=0;
        int j=n-1;

        for(int i=0;i<n;i++){
           int sqr=nums[i]*nums[i];
           ans.push_back(sqr);
        }
       
         sort(ans.begin(),ans.end());
         return ans;
    }
};