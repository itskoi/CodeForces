#include <iostream>

using namespace std;

int main() {
    int Q; cin >> Q;
    while(Q--) {
        int n; cin >> n;
        int x, sum;
        sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            sum += x;
        }
        if (sum % n == 0) cout << sum / n << endl;
        else cout << sum / n + 1 << endl;
    }
    return 0;
}