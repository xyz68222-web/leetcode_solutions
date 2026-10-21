class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        vector<int> nums2(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    nums2.push_back(nums1[j]);
                }
                else{
                    int r=nums1[j]-nums1[i];
                    nums2.push_back(r);
                }
            }
        }
        for(int i=0;i<nums2.size();i++){
            if(nums2[i]%2==0)
            return true;
            else return false;
        }
        return false;
    }
};