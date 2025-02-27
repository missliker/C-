#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct PerSegTree {
    int tot, n, inf;
    std::vector<int> rs, ls, cnt, sum, root;
    PerSegTree() {}
    PerSegTree(int _n, int _inf) { // 版本数，最大值
        init(_n, _inf);
    }
    void init(int _n, int _inf) {
        n = _n;
        inf = _inf;
        tot = 0;
        rs.resize(1, 0);
        ls.resize(1, 0);
        cnt.resize(1, 0);
        sum.resize(1, 0);
        root.resize(n, 0);
    }
    void apply(int& u, int v, int l, int r, int p) {
        u = ++tot;
        rs.emplace_back(), ls.emplace_back(), cnt.emplace_back(), sum.emplace_back();
        ls.back() = ls[v], rs.back() = rs[v], cnt.back() = cnt[v] + 1, sum.back() = sum[v] + p;
        if (l == r) return;
        int mid = (l + r) >> 1;
        if (p <= mid) apply(ls.back(), ls[v], l, mid, p);
        else apply(rs.back(), rs[v], mid + 1, r, p);
    }

    void apply(int v1, int v2, int p) { apply(root[v1], root[v2], 1, inf, p); }

    int query(int u, int v, int l, int r, int k) {
        if (l == r) return l;
        int s = cnt[ls[u]] - cnt[ls[v]];
        int mid = (l + r) >> 1;
        if (s >= k) return query(ls[u], ls[v], l, mid, k);
        else return query(rs[u], rs[v], mid + 1, r, k - s);
    }

    int query(int l, int r, int k) { return query(root[r], root[l], 1, inf, k); }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    PerSegTree seg(n + 1, 0);

    return 0;
}