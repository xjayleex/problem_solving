#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, time, a;
    cin >> N;
    vector <vector<int>> adj(N+1);
    vector <vector<int>> time_lists(N+1);
    vector <int> times(N+1);
    vector <int> inDegree(N+1);
    vector <int> ans(N+1);
    for (int i = 1 ; i <= N ; i++) {
        cin >> time;
        while(true){
            cin >> a;
            if(a == -1)
                break;
            adj[a].push_back(i);
            inDegree[i] += 1;
        }
        times[i] = time;
    }
    queue <pair<int,int>> q;
    for(int i = 1 ; i <= N ; i++) {
        if(inDegree[i] == 0)
            q.push(make_pair(i,times[i])); // nodeId, Times
    }
    while(!q.empty()) {
        pair<int,int> now = q.front(); q.pop();
        ans[now.first] = now.second;
        for (int i = 0 ; i < adj[now.first].size() ;i++) {
            int next = adj[now.first][i];
            inDegree[next] -= 1;
            time_lists[next].push_back(now.second + times[next]);
            if( inDegree[next] == 0) {
                int max_time = -1;
                for (int j = 0 ; j < time_lists[next].size() ; j++ ){
                    if(max_time < time_lists[next][j]) {
                        max_time = time_lists[next][j];
                    }
                }
                q.push(make_pair(next, max_time));
            }
        }
    }
    for (int i = 1 ; i <= N ; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}