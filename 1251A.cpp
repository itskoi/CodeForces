#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int T; cin >> T;
    while(T--) {
        string str;
        set<char> result;
        cin >> str;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] != str[i + 1]) {
                result.insert(str[i]);
            } else i++;
        }
        for (auto it : result) {
            cout << it;
        }
        cout << endl;
    }
    return 0;
}