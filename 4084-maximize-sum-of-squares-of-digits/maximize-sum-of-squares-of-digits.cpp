class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num || sum<1)
        return "";
        string ans="";
        for(int i=0;i<num;i++){
            int a=min(9,sum);
            ans.push_back('0'+ a);
            sum-=a;
        }
        return ans;
    }
};