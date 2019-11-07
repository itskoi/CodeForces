#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<long long, int> pii;

int main() {
    // Initialize
    int n; cin >> n;
    long long p; cin >> p;
    vector<pii> array;
    vector<long long>result(n + 1);
    priority_queue<int, vector<int>, greater<int>> pq; // Ds uu tien cho nhung nguoi gan cai am nuoc hon ne
    queue<int> q; // Danh sach theo thu tu nhung nguoi di rot nuoc ne 

    // Solving
    long long x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        array.push_back({x, i});
    }
    sort(array.begin(), array.end());

    long long cur = array[0].first;
    int idx = 0, cnt = 0;
    while(cnt < n) {
        while(idx < n && array[idx].first <= cur + p) {
            // Tim nhung nguoi se available cho lan rot nuoc tiep theo
            if (q.empty() || q.back() > array[idx].second) {
                q.push(array[idx++].second);
                // Danh sach q la hang doi don dieu giam dan
                // Neu stt cua thang dang xet (idx) < cai thang cuoi danh sach q
                // Thi chac chan no se la nguoi tiep theo duoc rot nuoc, sau cai thang q.back()
            } else {
                // Van la nhung nguoi co kha nang di lay nuoc
                // Nhung ma do thang q.back() no co stt nho hon ma no di lay truoc
                // Nen may thang sau nay phai uu tien thang co stt nho nhat
                pq.push(array[idx++].second);
            }
        }
        // Set the result
        cur += p;
        result[q.front()] = cur;
        q.pop();
        cnt++;
        // Cho thang co stt nho nhat lay nuoc ne
        if (q.empty() && !pq.empty()) {
            q.push(pq.top());
            pq.pop();
        }
    }


    // In ket qua thoy ma <3
    for (int i = 1; i <= n; i++) {
        cout << result[i] << ' ';
    }
    return 0;
}