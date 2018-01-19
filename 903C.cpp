#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define rep(i, a, b) for (int i = a; i <= b; i++)

int n, box[10101], ans;
bool _free[10101];

void Input() {
    memset(_free, 0, sizeof _free);
    cin >> n;
    rep(i, 1, n) cin >> box[i];
}

void Compute() {
    ans = n;
    sort(box + 1, box + n + 1);
    rep(i, 1, n - 1) {
        rep(j, i + 1, n) if (!_free[j] && box[j] > box[i]) {
            _free[j] = true;
             ans--;
             break;
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Input();
    Compute();
    return 0;
}
