#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rep2(i, a, b) for (int i = a; i >= b; i--)

int n, L;
int c[33];
ll ans = 1e18, sum = 0;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> L;
    rep(i, 1, n) cin >> c[i];
    rep(i, 2, n) c[i] = min(c[i], c[i - 1] * 2);
    rep2(i, n, 1) {
        int cnt = L / (1 << (i - 1));
        sum += 1ll * cnt * c[i];
        L -= cnt << (i - 1);
        ans = min(ans, sum + (L > 0) * c[i]);
    }
    cout << ans;
    return 0;
}
