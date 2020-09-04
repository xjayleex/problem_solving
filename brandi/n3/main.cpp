#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector <pair<int,int>> adj[201];
    vector <int> upper(N+1, INT_MAX); upper[0] = upper[1] = 0;
    int a,b,w;
    for (int i = 0 ; i < M ; i++) {
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b,w));
    }
    bool updated;
    for (int iter = 0 ; iter < N ; iter++) {
        updated = false;
        for(int here = 1 ; here <= N ; here++) {
            if(upper[here] == INT_MAX)
                continue;
            for(int j = 0 ; j < adj[here].size() ; j++) {
                int there = adj[here][j].first;
                int cost = adj[here][j].second;
                if(upper[there] > upper[here] + cost) {
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }
        }
        if(!updated)
            break;
    }
    if(updated)
        cout << "bug" << '\n';
    else {
        if (upper[N] == INT_MAX)
            cout << "bug" << '\n';
        else
            cout << upper[N] << '\n';
    }
    return 0;
}