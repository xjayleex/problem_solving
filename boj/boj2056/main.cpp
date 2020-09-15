#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int inDegree[10001];
vector<int> adj[10001];
int times[10001];
int elapsed[10001];
queue <int> q;
int bigger(const int &a, const int &b) {
    return a > b ? a:b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,tmp;
    cin >> N;
    for (int i = 1 ; i <= N ; i++) {
        cin >> times[i];
        elapsed[i] = times[i];
        cin >> inDegree[i];
        for (int j = 0 ; j < inDegree[i] ; j++) {
            cin >> tmp;
            adj[tmp].push_back(i);
        }
    }
    for(int i = 1; i <= N ;i++) {
        if(inDegree[i]==0)
            q.push(i);
    }
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for(int i = 0 ; i < adj[now].size() ;i++) {
            int next = adj[now][i];
            inDegree[next] -= 1;
            int nt = elapsed[now] + times[next];
            if (elapsed[next] < nt)
                elapsed[next] = nt;
            if(inDegree[next] != 0) continue;
            q.push(next);
        }
    }
    int max = -1;
    for (int i = 1 ; i <= N ; i++) {
        max = bigger(max,elapsed[i]);
    }
    cout << max << '\n';

    return 0;
}