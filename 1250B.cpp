#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

typedef long long ll;

int n, k;
int a[8080];// so luong thanh vien cua tung teams
vector<int> list; // cung la so luong thanh vien, nhung theo thu tu tu it den nhieu
int main() {    
    // Initialize
    cin >> n >> k;
    memset(a, 0, sizeof a);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x]++;
    }
    for (int i = 1; i <= k; i++) {
        list.push_back(a[i]);
    }
    sort(list.begin(), list.end());

    // Solving
    int rmax, rmin; // So chuyen bus max va min
    rmax = k, rmin = (k / 2) + (k % 2); // moi xe cho toi da 2 teams
    long long res = 1e18;
    for (int i = rmin; i <= rmax; i++) {
        // neu so chuyen xe < rmax | thi chac chan co xe cho 1 team 
        // uu tien team co so thanh vien nhieu nhat
        int j = 0, t = (k - i) * 2 - 1; 
        long long cap = 0;
        // Tim capacity thoa man | de luon cho duoc 2 teams
        while(j < t) {
            cap = max(cap, 1LL * (list[j] + list[t]));
            j++; t--;
        }
        // If t - j + 1 is odd number
        if (j == t) {
            cap = max(cap, 1LL * (list[j]));
        }

        // Kiem tra may team ma chiem het ca 1 chiec xe buyt ne
        for (int z = (k - i) * 2; z < k; z++) {
            cap = max(cap, 1LL * (list[z]));
        }
        res = min(res, i * cap);
    }
    cout << res;
    return 0;
}