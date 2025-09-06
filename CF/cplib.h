// ================== cp_lib.h ==================
#pragma once
#include <bits/stdc++.h>
using namespace std;

// ---------- Mint (modular int) ----------
struct mint
{
    static const int MOD = 998244353; // change if needed
    int v;
    mint(long long _v = 0)
    {
        if (_v < 0)
            _v = _v % MOD + MOD;
        if (_v >= MOD)
            _v %= MOD;
        v = int(_v);
    }
    explicit operator int() const { return v; }
    mint &operator+=(const mint &o)
    {
        if ((v += o.v) >= MOD)
            v -= MOD;
        return *this;
    }
    mint &operator-=(const mint &o)
    {
        if ((v -= o.v) < 0)
            v += MOD;
        return *this;
    }
    mint &operator*=(const mint &o)
    {
        v = int((1LL * v * o.v) % MOD);
        return *this;
    }
    mint &operator/=(const mint &o) { return *this *= o.inv(); }
    friend mint operator+(mint a, const mint &b) { return a += b; }
    friend mint operator-(mint a, const mint &b) { return a -= b; }
    friend mint operator*(mint a, const mint &b) { return a *= b; }
    friend mint operator/(mint a, const mint &b) { return a /= b; }
    mint pow(long long p) const
    {
        mint a = *this, res = 1;
        while (p > 0)
        {
            if (p & 1)
                res *= a;
            a *= a;
            p >>= 1;
        }
        return res;
    }
    mint inv() const { return pow(MOD - 2); }
};

// ---------- DSU ----------
struct dsu
{
    vector<int> p, sz;
    dsu(int n = 0) { init(n); }
    void init(int n)
    {
        p.resize(n);
        sz.assign(n, 1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (sz[a] < sz[b])
            swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

// ---------- Fenwick Tree ----------
struct fenwick
{
    int n;
    vector<long long> bit;
    fenwick(int n = 0) { init(n); }
    void init(int n_)
    {
        n = n_;
        bit.assign(n + 1, 0);
    }
    void add(int idx, long long val)
    {
        for (++idx; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }
    long long sum(int idx)
    {
        long long r = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            r += bit[idx];
        return r;
    }
    long long range_sum(int l, int r) { return sum(r) - sum(l - 1); }
};

// ---------- Segment Tree ----------
template <class T, class F>
struct segtree
{
    int n;
    vector<T> t;
    F f;
    T id;
    segtree(int n, F f, T id) : f(f), id(id)
    {
        this->n = 1;
        while (this->n < n)
            this->n <<= 1;
        t.assign(2 * this->n, id);
    }
    void set_val(int i, T v)
    {
        t[i += n] = v;
        for (i >>= 1; i; i >>= 1)
            t[i] = f(t[2 * i], t[2 * i + 1]);
    }
    T query(int l, int r)
    {
        T L = id, R = id;
        for (l += n, r += n; l <= r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                L = f(L, t[l++]);
            if (!(r & 1))
                R = f(t[r--], R);
        }
        return f(L, R);
    }
};
// ==========================================
