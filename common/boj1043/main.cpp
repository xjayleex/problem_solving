#include <iostream>
#include <vector>

using namespace std;
vector<int> adj[51];
bool visited[51];
void dfs(int node) {
    visited[node] = true;
    for (int i = 0 ; i < adj[node].size() ;i++) {
        int next = adj[node][i];
        if (visited[next])
            continue;
        dfs(next);
    }
}
int main() {
    int cnt = 0;
    int N, M, K, t;
    cin >> N >> M;
    cin >> K;
    vector<int> truth;
    if (K != 0)
        truth.resize(K);
    for (int i = 0 ; i < K ; i++) {
        cin >> truth[i];
    }
    vector<vector<int>> party;
    vector<int> thirdParty;

    for (int i = 0 ; i < M ;i++){
        cin >> t;
        if (t == 0) {
            cnt += 1;
            continue;
        } else if (t == 1) {
            cin >> t;
            thirdParty.push_back(t);
            continue;
        }
        vector <int> p(t);
        for (int j = 0 ; j < t ; j++) {
            cin >> p[j];
        }
        for (int j = 0 ; j < p.size()-1;j++) {
            adj[p[j]].push_back(p[j+1]);
            adj[p[j+1]].push_back(p[j]);
        }
        party.push_back(p);
    }
    for(int i = 0 ; i < truth.size() ; i++ ) {
        dfs(truth[i]);
    }
    for(int i = 0 ; i < party.size() ; i++) {
        bool f = true;
        for (int j = 0 ; j < party[i].size() ;j++) {
            if(visited[party[i][j]]){
                f = false; break;
            }
        }
        if(f) cnt++;
    }
    for(int i = 0 ; i < thirdParty.size() ; i++) {
        if(!visited[thirdParty[i]]) cnt++;
    }
    cout << cnt << '\n';

    return 0;
}