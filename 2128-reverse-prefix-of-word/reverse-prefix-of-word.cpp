class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n=word.size();
        string ans="";
        int len=0;
        for(int i=0;i<n;i++){
            ans.push_back(word[i]);
            len++;
            if(ans[i]==ch){
                reverse(ans.begin(),ans.end());
                ans += word.substr(i + 1);
                return ans;
            }
        }
        return word;
    }
};