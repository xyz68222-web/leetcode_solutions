class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ve;
        int mn=INT_MAX;
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
             int x=nums[i];
             mn=min(mn,x);
             mx=max(mx,x);
             }
        while(mn<=mx){
            ve.push_back(mn);
            mn++;
        }
        vector<int> ans;
        int i=0;
        int j=0;
        while(i<nums.size() && j<ve.size()){
            if(nums[i]==ve[j]){
                i++;
                j++;
            }
            else{
                ans.push_back(ve[j]);
                j++;
            }
        }
        return ans;
    }
};