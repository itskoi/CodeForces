#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n;
vector<int> adj[1010];
bool leaf[1010];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    memset(leaf, 1, sizeof leaf);
    leaf[1] = false;
    for(int i = 2; i <= n; i++) {
        int x; cin >> x;
        leaf[x] = false;
        adj[x].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        if (!leaf[i]) {
            vector<int>::iterator it;
            int tmp = 0;
            for (it = adj[i].begin(); it != adj[i].end(); it++)
                if (leaf[*it]) tmp++;
            if (tmp < 3) {
                cout << "NO"; return 0;
            }
        }
    cout << "YES";
    return 0;
}
