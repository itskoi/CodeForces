#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Post {
    int pos, minPos, maxPos;
    Post(int _pos) : pos(_pos), minPos(_pos), maxPos(_pos) {}
};  

int n, m;
vector<Post> posts; // Danh sach cac post theo thu tu ban dau 
vector<int> showPos; // Cho biet tai vi tri i hien tai la post nao

void update(int idx) {
    posts[idx].maxPos = min(posts[idx].maxPos, posts[idx].pos);
    posts[idx].minPos = max(posts[idx].minPos, posts[idx].pos);
}

int main() {
    // Initialize
    cin >> n >> m;
    posts.push_back(Post(-1));
    showPos.push_back(-1);
    for (int i = 1; i <= n; i++) {
        posts.push_back(Post(i));
        showPos.push_back(i);
    }
    // Solving
    while(m--) {
        int idx; cin >> idx;
        if (posts[idx].pos != 1) {
            int otherPost = showPos[--posts[idx].pos];
            showPos[posts[idx].pos] = idx;
            posts[otherPost].pos++;
            showPos[posts[otherPost].pos] = otherPost;
            update(otherPost);
            update(idx);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << posts[i].maxPos << " " << posts[i].minPos;
        cout << endl;
    }
    return 0;
}