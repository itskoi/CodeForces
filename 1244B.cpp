#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool visited[10101][3];
int dp[101010][3];

int dfs(int u, int curLevel, int n, string floor) {
    int result;
    int a, b, c;
    a = b = c = 0;
    dp[u][curLevel] = 1;
    visited[u][curLevel] = true;
    if (u + 1 <= n && !visited[u + 1][curLevel]) a = dfs(u + 1, curLevel, n, floor);
    if (u - 1 >= 1 && !visited[u - 1][curLevel]) b = dfs(u - 1, curLevel, n, floor);
    if (floor[u] == '1' && curLevel == 1 && !visited[u][2]) 
        c = dfs(u, 2, n, floor);
    if (floor[u] == '1' && curLevel == 2 && !visited[u][1]) 
        c = dfs(u, 1, n, floor);
    result = max(a, b);
    result = max(result, c);
    return dp[u][curLevel] + result;
}

int main() {
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        string floor;
        cin >> floor;
        floor = " " + floor;
        //
        memset(visited, false, sizeof visited);
        memset(dp, 0, sizeof dp);
        int result = dfs(1, 1, n, floor);
        //memset(visited, false, sizeof visited);
        memset(visited, false, sizeof visited);
        memset(dp, 0, sizeof dp);
        result = max(dfs(n, 1, n, floor), result);
        cout << result << endl;
    }
    return 0;
}