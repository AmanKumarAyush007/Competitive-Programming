#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define nl '\n'
#define all(a)(a).begin(), (a).end()

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    ll sum = 0;
    int min_abs_value = INT_MAX;
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        sum += abs(A[i]);
        if (A[i] < 0) {
            cnt++;
        }
        min_abs_value = min(min_abs_value, abs(A[i]));
    }

    if (cnt% 2 == 1) {
        sum -= 2 * min_abs_value;
    }

    cout << sum << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}