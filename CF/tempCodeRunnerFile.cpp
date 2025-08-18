#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SegmentTree {
    int n;
    vector<vector<int>> tree;

    void build(vector<int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = {a[tl]};
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            // merge the sorted vectors from children
            merge(tree[v*2].begin(), tree[v*2].end(),
                  tree[v*2+1].begin(), tree[v*2+1].end(),
                  back_inserter(tree[v]));
        }
    }

    // Query: count of elements > k in [l, r]
    int query(int v, int tl, int tr, int l, int r, int k) {
        if (l > r) return 0;
        if (tl == l && tr == r) {
            // Elements in tree[v] are sorted; find first greater than k
            auto it = upper_bound(tree[v].begin(), tree[v].end(), k);
            return tree[v].end() - it;
        }
        int tm = (tl + tr) / 2;
        return query(v*2, tl, tm, l, min(r, tm), k) +
               query(v*2+1, tm+1, tr, max(l, tm+1), r, k);
    }

public:
    SegmentTree(vector<int> &a) {
        n = a.size();
        tree.resize(4*n);
        build(a, 1, 0, n-1);
    }

    int range_greater(int l, int r, int k) {
        // Convert to 0-based indexing
        return query(1, 0, n-1, l, r, k);
    }
};

int main() {
    vector<int> a = {3 ,1 ,5 ,2 ,7 ,6 ,4};
    SegmentTree st(a);
    int l = 0, r = 6, k = 3; // Query: indices 1-4, k=4
    cout << st.range_greater(l, r, k) << endl; // Output: 2 (for 5 and 8)
    return 0;
}

