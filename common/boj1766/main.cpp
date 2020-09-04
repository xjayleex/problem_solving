#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 32000+1
int inDegree[MAX];
int N, M;
/*
struct Problem {
    int time;
    int diffculty;
};
struct compare{
    bool operator()(const Problem &a, const Problem &b){
        if(a.time == b.time)
            return a.diffculty > b.diffculty;
        else
            return a.time > b.time;
    }
};*/
int main() {
    vector <int> ans;
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    priority_queue <int,vector<int>,greater<>> pq;
    cin >> N >> M;
    int a,b;
    vector<vector<int>> adj(N+1);
    for (int i = 0 ; i < M ; i++) {
        cin >> a >> b;
        inDegree[b] += 1;
        adj[a].push_back(b);
    }
    for (int i = 1 ; i<= N;i++){
        if (inDegree[i] == 0)
            pq.push(i);
    }
    while(!pq.empty()) {
        int diff  = pq.top(); pq.pop();
        ans.push_back(diff);
        for(int i = 0 ; i < adj[diff].size() ; i++) {
            int next = adj[diff][i];
            inDegree[next] -= 1;
            if (inDegree[next] == 0) {
                pq.push(next);
            }
        }
    }
    for (int i = 0; i < ans.size() ;i++ ) {
        cout << ans[i] << ' ';
    }
    return 0;
}