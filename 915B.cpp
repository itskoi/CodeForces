#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, pos, l, r;

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> pos >> l >> r;
    if (l == 1 && r == n) cout << 0;
    else if (l == 1) cout << abs(r - pos)+1;
    else if (r == n) cout << abs(pos - l) + 1;
    else {
        cout << min(abs(pos - l), abs(pos - r)) + 1 + r - l + 1;
    }
    return 0;
}
