class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<tuple<int, int, int>> st;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            st.push_back({sum, nums[i], i});
        }

        sort(st.begin(), st.end());

        vector<bool> vis(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || get<2>(st[i]) == i)
                continue;

            int j = i;
            int cycle = 0;

            while (!vis[j]) {
                vis[j] = true;
                j = get<2>(st[j]);
                cycle++;
            }

            count += cycle - 1;
        }

        return count;
    }
};