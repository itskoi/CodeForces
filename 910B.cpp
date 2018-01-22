#include <iostream>

using namespace std;

int n, a, b, ans = 0;

int main() {
    cin >> n >> a >> b;
    int ans = 6;
    if (2 * a <= n) ans -= 2;
    if (2 * b <= n) ans -= 1;
    if (4 * a <= n) ans -= 1;
    if (a + b <= n) {
        if (2 * a <= n) ans = 3;
        else ans = 4;
    }
    if (2 * a + b <= n) ans = 2;
    if (2 * (2 * a + b) <= n) ans = 1;
    cout << ans;
    return 0;
}
