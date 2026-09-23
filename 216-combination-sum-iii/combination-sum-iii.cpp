class Solution {
public:
 void solve(int i,int k,int n,vector<int>& temp, vector<vector<int>>& ans){
    if(k==0 && n==0){
        ans.push_back(temp);
        return;
    }
    if(k==0 || n<=0){
        return ;
    }
    for(int r=i;r<=9;r++){
        temp.push_back(r);

        solve(r+1,k-1,n-r,temp,ans);
        temp.pop_back();
    }
 }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
         
         solve(1,k,n,temp,ans);
         return ans;

    }
};