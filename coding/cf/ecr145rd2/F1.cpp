#include <bits/stdc++.h>
 
using i64 = long long;
 
void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    
    i64 sum = std::accumulate(a.begin(), a.end(), 0LL);
    
    std::vector<i64> f(2 * n + 1);
    for (int i = 0; i < 2 * n; i++) {
        f[i + 1] = f[i] + a[i % n];
    }
    
    int last = -1;
    std::vector<int> pre(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        if (b[i % n] == 1) {
            last = i;
        }
        pre[i] = last;
    }
    
    std::vector<i64> ans(n);
    ans[0] += sum;
    for (int i = 0; i < 2 * n - 1; i++) {
        if (b[i % n] == 2) {
            if (pre[i] == -1) {
                ans[std::max(0, i - n + 1)] += a[i % n];
                if (i + 1 < n) {
                    ans[i + 1] -= a[i % n];
                }
            } else {
                int v = std::max(0LL, std::min(1LL * a[i % n], f[i + 1] - f[pre[i]] - k));
                ans[std::max(0, i - n + 1)] += v;
                if (pre[i] + 1 < n) {
                    ans[pre[i] + 1] += a[i % n] - v;
                }
                if (i + 1 < n) {
                    ans[i + 1] -= a[i % n];
                }
            }
        }
    }
    for (int i = 1; i < n; i++) {
        ans[i] += ans[i - 1];
    }
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
