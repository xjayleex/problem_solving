#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct H {
    int node;
    int inDegreeCnt;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M, a, b;
    cin >> N >> M;
    vector <H> heights(N+1);
    queue<H> q;
    vector <vector<int>> adj(N+1);
    for (int i = 0 ; i < M ; i++) {
        cin >> a >> b;
        heights[b].node = b;
        heights[b].inDegreeCnt += 1;
        adj[a].push_back(b);
    }
    for (int i = 1 ; i <= N; i++){
        if (heights[i].node == 0) {
            heights[i].node = i;
        }
    }
    for (int i = 1 ; i <= N ; i++ ) {
        if(heights[i].inDegreeCnt == 0) {
            q.push(heights[i]);
            //cout << "Zero Indegree node : " << heights[i].node << '\n';
        }
    }

    while(!q.empty()) {
        H now = q.front(); q.pop();
        cout << now.node << ' ';
        for (int i = 0 ; i < adj[now.node].size() ; i++) {
            int nextNode = adj[now.node][i];
            heights[nextNode].inDegreeCnt -= 1;
            if(heights[nextNode].inDegreeCnt == 0)
                q.push(H{heights[nextNode].node,nextNode});
        }
    }
    return 0;
}