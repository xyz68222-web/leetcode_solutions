class Solution {
public:
    unordered_set<string> visited;
    string ans;
    int n, k;

    void dfs(string node) {
        for (int i = 0; i < k; i++) {
            char ch = '0' + i;
            string edge = node + ch;

            if (!visited.count(edge)) {
                visited.insert(edge);
                dfs(edge.substr(1));
                ans += ch;
            }
        }
    }

    string crackSafe(int n, int k) {
        this->n = n;
        this->k = k;

        string start(n - 1, '0');  // string length L>=pow(k,n)+n-1
        dfs(start);

        ans += start;
        return ans;
    }
};