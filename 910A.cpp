#include <iostream>
#include <string>

using namespace std;

string s;
int n, d;

int main() {
    int cur = 1, cnt = 0;
    cin >> n >> d >> s; s = " " + s;
    while(cur != n) {
        bool found = false;
        for (int i = cur + d; i >= cur + 1; i--) {
            if (s[i] == '1') {
                cur = i; found = true; break;
            }
        }
        if (!found) {
            cout << -1; return 0;
        }
        cnt += 1;
    }
    cout << cnt;
    return 0;
}
