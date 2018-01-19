#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
#define rep(i, a, b) for (int i = a; i <= b; i++)

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string fi, se, res = "", pre1, pre2;
    cin >> fi >> se;
    int index = 0, pivot;
    pre1 = pre2 = "";
    pre1 += fi[0]; pre2 += se[0];
    res = pre1 + pre2;
    rep(i, 1, fi.size() - 1) {
        pre1 += fi[i];
        string tmp = pre1 + pre2;
        if (tmp < res) res = tmp;
    }
    cout << res;
    return 0;
}
