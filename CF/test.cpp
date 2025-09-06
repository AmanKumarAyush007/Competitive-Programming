#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;

int main() {
    int n;
    cin >> n;
    // By default, modint998244353 uses MOD = 998244353
    using mint = modint;

    mint :: set_mod(7);

    mint a = 10;
    mint b = 20;

    // Basic operations
    mint c = a + b;  // 30
    mint d = a * b;  // 200
    mint e = d.pow(5); // 200^5 mod 998244353

    cout << "a = " << a.val() << "\n";
    // cout << "b = " << b.val() << "\n";
    // cout << "a + b = " << c.val() << "\n";
    // cout << "a * b = " << d.val() << "\n";
    // cout << "d^5 = " << e.val() << "\n";

    // Inverse test (modular inverse)
    // cout << "Inverse of a = " << a.inv().val() << "\n";
}
