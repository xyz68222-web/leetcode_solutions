class Solution {
public:
//sorted
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> sorted;
        int i=0,j=0; 
        while(i<n && j<m){
            if(nums1[i]<nums2[j])
            sorted.push_back(nums1[i++]);
            else
            sorted.push_back(nums2[j++]);
        }
        while(i<n)
        sorted.push_back(nums1[i++]);
        while(j<m)
        sorted.push_back(nums2[j++]);
        int k=sorted.size();
        if(k%2==0)
        return (sorted[k/2-1]+sorted[k/2])/2.0;
        else
        return sorted[k/2];
    }
};