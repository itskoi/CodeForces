#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int score = 0;
        for (int j = 0; j < 3; j++) {
            int x; cin >> x;
            score += x;
        }
        if (score >= 2) ans++;
    }
    cout << ans;
    return 0;
}
