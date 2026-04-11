#include<bits/stdc++.h>
using namespace std;

const int N = 200000 + 5;
int divisors[N];

void precompute() {
    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i) {
            divisors[j]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    // Example: print divisor count of some numbers
    for(int i = 1; i <= 10; i++) {
        cout << i << " -> " << divisors[i] << '\n';
    }

    return 0;
}