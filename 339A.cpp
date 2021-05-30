#include <bits/stdc++.h>

using namespace std;
 
int main() {
    int one, two, three;
    one = two = three = 0;
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '1') one++;
        else if (s[i] == '2') two++;
        else if (s[i] == '3') three++;
    string ans = "";

    while(one) {
        ans += '1';
        one--;
        if (one > 0 | two > 0 | three > 0)
            ans += '+';
    }
    while(two) {
        ans += '2';
        two--;
        if (two > 0 | three > 0)
            ans += '+';
    }
    while(three) {
        ans += '3';
        three--;
        if (three > 0)
            ans += '+';
    }
    cout << ans;
    return 0;
}
