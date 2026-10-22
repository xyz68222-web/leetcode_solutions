
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> height(n, 0);
        vector<int> left(n, 0);
        vector<int> right(n, n);

        int ans = 0;

        for (int i = 0; i < m; i++) {
            int currLeft = 0;
            int currRight = n;

            // Update heights
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            // Update left boundaries
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    left[j] = max(left[j], currLeft);
                else {
                    left[j] = 0;
                    currLeft = j + 1;
                }
            }

            // Update right boundaries
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1')
                    right[j] = min(right[j], currRight);
                else {
                    right[j] = n;
                    currRight = j;
                }
            }

            // Calculate maximum area
            for (int j = 0; j < n; j++) {
                ans = max(ans, height[j] * (right[j] - left[j]));
            }
        }

        return ans;
    }
};
