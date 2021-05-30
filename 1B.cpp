#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int StrToInt(string str) {
    int result = 0;
    int pow = 1;
    for (auto x : str) {
        result += int(x - '0') * pow;
        pow *= 10;
    }
    return result;
}

int main() {
    int T; cin >> T;
    string str = "";
    while(T--) {
        cin >> str;
        auto x = str.find('C');
        if (str[0] == 'R' && x != string::npos && str[int(x) - 1] >= '0' && str[int(x) - 1] <= '9') {
            string row, col;
            row = col = "";
            auto x = str.begin();
            for (auto it = str.begin() + 1; it != str.end(); it++) {
                if (*it == 'C') {
                    x = it;
                    break;
                }
                row = row + *it;
            }
            x++;
            for (auto it = x; it != str.end(); it++) {
                col = *it + col;
            }
            int rcol = StrToInt(col);
            col = "";
            int nho = 0;
            while(rcol > 0) {
                int x = rcol % 26;
                if (x == 0) {
                    x = 26;
                }
                rcol -= x;
                col = char(x + 65 - 1) + col;
                rcol /= 26;           
            }
            cout << col << row << endl;
        } else {
            string col = "";
            cout << "R";
            for (auto x : str) {
                if (x <= 'Z' && x >= 'A') {
                    col = x + col;
                } else {
                    cout << x;
                }
            }
            cout << "C";
            int rcol = 0;
            int pow = 1;
            for (auto x : col) {
                rcol += int(x - 'A' + 1) * pow;
                pow *= 26;
            }
            cout << rcol << endl;
        }
    }
    return 0;
}
