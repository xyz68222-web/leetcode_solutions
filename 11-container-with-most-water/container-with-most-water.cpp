class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int sum=0;
        while(i<j){
          int heigh=(j-i);
          int width=min(height[i],height[j]);
          int area=width*heigh;
            sum=max(sum,area);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return sum;

    }
};