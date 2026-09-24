class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        vector<int> ans_s;
        vector<int> ans_o;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                ans_s.push_back(nums[i]);
            }
            else{
                ans_o.push_back(nums[i]);
            }
        }
       int i=0;
       int j=0;
        for(int k=0;k<n;k++){
           if(k%2==0){
            ans[k]=ans_s[i];
            i++;
         }
         else{
              ans[k]=ans_o[j];
                j++;
            }
        }
        return ans;
    }
};