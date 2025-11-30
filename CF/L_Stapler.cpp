#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int xl, yl, xr, yr;
    cin >> xl >> yl >> xr >> yr;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // 1. Endpoint inside rectangle check
    auto inside = [&](int x, int y) {
        return (xl <= x && x <= xr && yl <= y && y <= yr);
    };
    if (inside(x1,y1) || inside(x2,y2)) {
        cout << "STOP\n";
        return;
    }

    // 2. Liang–Barsky
    double dx = x2 - x1;
    double dy = y2 - y1;
    double t_enter = 0, t_exit = 1;

    vector<pair<double,double>> constraints = {
        {-dx, double(x1 - xl)},
        { dx, double(xr - x1)},
        {-dy, double(y1 - yl)},
        { dy, double(yr - y1)}
    };

    for (auto [p,q] : constraints) {
        if (p == 0) {
            if (q < 0) {
                cout << "OK\n"; // line is parallel and outside
                return;
            }
            // else parallel and inside → continue
        } else {
            double val = q / p;
            if (p < 0) {
                t_enter = max(t_enter, val);
            } else {
                t_exit = min(t_exit, val);
            }
        }
    }

    if (t_enter <= t_exit) cout << "STOP\n";
    else cout << "OK\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
