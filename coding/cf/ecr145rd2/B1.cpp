#include <bits/stdc++.h>
 
using i64 = long long;
 
void solve() {
    i64 n;
    std::cin >> n;
    
    i64 x = std::sqrt(n);
    // case 1: x*x == n
    // case 2: x*x < n
    //         (x+1)*(x+1) > n
    if (x * x < n) {
        x += 1;
    }
    // while ((x - 1) * (x - 1) >= n) {
    //     x -= 1;
    // }
    
    x -= 1;
    
    std::cout << x << "\n";
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
