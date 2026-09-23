class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int> st(nums.begin(),nums.end());
         //let s=k;

         int x=k;
         while(st.count(x)){// if x is exist in set st
            x+=k;
         }
         return x;
    }
};