class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // Case 1: nums is a cyclic rotation of sorted order
        bool inc = true;
        int s = nums[0];

        for (int i = 0; i < n; i++) {
            if (nums[i] != (s + i) % n) {
                inc = false;
                break;
            }
        }

        int ans = INT_MAX;

        if (inc) {
            if (s == 0) {
                ans = 0;
            } else {
                ans = min(n - s, s + 2);
            }
        }

        // Case 2: nums is a cyclic rotation of reverse-sorted order
        bool dec = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (s - i + n) % n) {
                dec = false;
                break;
            }
        }

        if (dec) {
            int k = (n - 1 - s + n) % n;
            ans = min(ans, min(k, n - k) + 1);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};