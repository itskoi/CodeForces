#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int one, two;
        one = two = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x == 1) one++;
            else two++;
        }
        if (one % 2 == 1) cout << "NO\n";
        else {
            if (two % 2 == 0 || one >= 2) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
