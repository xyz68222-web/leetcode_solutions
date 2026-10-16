class Solution {
public:

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    int n;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        tree[node].sq =
            (tree[node].sq
             + 2LL * val * tree[node].sum
             + len * val % 1000000007 * val) % 1000000007;

        tree[node].sum =
            (tree[node].sum + len * val) % 1000000007;

        tree[node].lazy =
            (tree[node].lazy + val) %1000000007;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;
        long long val = tree[node].lazy;

        apply(node * 2, l, mid, val);
        apply(node * 2 + 1, mid + 1, r, val);

        tree[node].lazy = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        tree[node].sum =
            (tree[node * 2].sum +
             tree[node * 2 + 1].sum) % 1000000007;

        tree[node].sq =
            (tree[node * 2].sq +
             tree[node * 2 + 1].sq) % 1000000007;
    }

    int sumCounts(vector<int>& nums) {
       /* int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            unordered_set<int> st;
            for(int j=i;j<n;j++){
                st.insert(nums[j]);
            long long count=st.size();
            sum=(sum+count*count)%1000000007;
           }
        }
        return sum;*/
n = nums.size();
        tree.assign(4 * n + 5, Node());

        unordered_map<int, int> last;
        long long ans = 0;

        for (int j = 0; j < n; j++) {
            int prev = -1;

            if (last.count(nums[j]))
                prev = last[nums[j]];

            update(1, 0, n - 1, prev + 1, j);

            last[nums[j]] = j;

            ans = (ans + tree[1].sq) % 1000000007;
        }

        return ans;
    }
};