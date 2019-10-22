#include <iostream>

using namespace std;

int main() {
    int T; cin >> T;
    while(T--) {
        long long x, y; cin >> x >> y;
        if (x - y <= 1) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}