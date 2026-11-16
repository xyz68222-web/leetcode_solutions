class Solution {
public:
    int minLength(string s) {
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            ans.push_back(s[i]);
            int m=ans.size();
            if(m>=2){
              if((ans[m-2]=='A' && ans[m-1]=='B') ||
                (ans[m-2]=='C' && ans[m-1]=='D')){
                 ans.pop_back();
                 ans.pop_back();
                }
            }
        }
        return ans.size();
    }
};