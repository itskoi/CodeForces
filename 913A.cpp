#include <iostream>

using namespace std;

int pow(int a, int n) {
    if (n == 0) return 1;
    int tmp = pow(a, n/2);
    if (n % 2) return tmp * tmp * a;
    return tmp * tmp;
}

int main() {
    int n, m; cin >> n >> m;
    if (n > 30) cout << m;
    else cout << m % pow(2, n);
    return 0;
}
