class Solution {
public:
    unordered_map<int, vector<int>> adj;
    vector<int> path;

    void dfs(int node) {
        while (!adj[node].empty()) {
            int next = adj[node].back();
            adj[node].pop_back();

            dfs(next);
        }

        path.push_back(node);
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, int> in, out;

        for (auto &p : pairs) {
            int u = p[0];
            int v = p[1];

            adj[u].push_back(v);
            out[u]++;
            in[v]++;
        }

        int start = pairs[0][0];

        for (auto &p : pairs) {
            int u = p[0];

            if (out[u] - in[u] == 1) {
                start = u;
                break;
            }
        }

        dfs(start);

        reverse(path.begin(), path.end());

        vector<vector<int>> ans;

        for (int i = 1; i < path.size(); i++) {
            ans.push_back({path[i - 1], path[i]});
        }

        return ans;
    }
};