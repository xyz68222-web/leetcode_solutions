class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size();
        int lo=0;
        int hi=n;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(s[i]=='I'){
                ans.push_back(lo);
                lo++;
            }
            if(s[i]=='D'){
                ans.push_back(hi);
                hi--;
            }
        }
        ans.push_back(lo);
       return ans;
    }
};