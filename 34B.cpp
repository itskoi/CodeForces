#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, a[101010], ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) a[i] = -a[i];
    for (int i = 1; i <= m; i++) if (ans + a[i] > ans) ans += a[i];
    cout << ans;
    return 0;
}
