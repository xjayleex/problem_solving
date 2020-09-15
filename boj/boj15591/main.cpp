#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
#define MAX 5001
int N,Q, p, q, r, k, v;
vector < pair<int,int> > rel[MAX];
bool visited[5001];
int smaller(const int &a, const int &b) {
    return a < b ? a : b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;
    for(int i = 0 ; i < N - 1; i++) {
        cin >> p >> q >> r;
        rel[p].push_back(make_pair(q,r));
        rel[q].push_back(make_pair(p,r));
    }
    for (int i = 0 ; i < Q ; i++) {
        cin >> k >> v;
        memset(visited,false,sizeof(visited));
        queue <int> q;
        int cnt = 0;
        q.push(v); visited[v] = true;
        while(!q.empty()) {
            int now = q.front(); q.pop();
            for(int i = 0 ; i < rel[now].size() ;i++) {
                int next = rel[now][i].first;
                int r = rel[now][i].second;
                if (visited[next]) continue;
                if(r < k) continue;
                cnt += 1;
                visited[next] = true;
                q.push(next);
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}