#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define rep(i, a, b) for (int i = a; i <= b; i++)

int n, k, ans = 0;
vector<int> A;

bool check(int key) {
    if (k % key) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    A.push_back(-1e9);
    rep(i, 1, n) {
        int x; cin >> x; A.push_back(x);
    }
    sort(A.begin(), A.end());
    rep(i, 1, n) if (check(A[i])) ans = k / A[i];
    cout << ans;
    return 0;
}
