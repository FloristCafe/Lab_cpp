#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    long long ans = 0;

    do {
        long long v = 0;
        for (int i = 1; i <= n; i++) {
            v += a[i - 1] ^ i;
        }
        ans |= v;
    } while (next_permutation(a.begin(), a.end()));

    cout << ans << '\n';
    return 0;
}