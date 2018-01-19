#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
    int ans = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a' || s[i] == 'o' || s[i] == 'e' || s[i] == 'u' || s[i] == 'i') ans++;
        if (s[i] == '1' || s[i] == '3' || s[i] == '5' || s[i] == '7' || s[i] == '9') ans++;
    }
    cout << ans;
    return 0;
}
