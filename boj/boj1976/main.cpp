#include <iostream>
#include <vector>
using namespace std;
int N,M;
int parent[201];
int findParent(int x) {
    if(parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]);
}
void Union(int x, int y) {
    int x_root = findParent(x);
    int y_root = findParent(y);
    if( x_root == y_root ) return;
    parent[y_root] = x_root;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M; int tmp;
    vector <vector<int>> adj(N+1);
    vector <int> cities;
    for (int i = 0 ; i < N ; i ++) {
        for (int j = 0 ; j < N ; j++) {
            cin >> tmp;
            if (tmp == 1) {
                adj[i+1].push_back(j+1);
            }
        }
    }
    for(int i = 0; i < M ; i++) {
        cin >> tmp;
        cities.push_back(tmp);
    }
    for (int i = 1 ; i <= N ;i++) {
        parent[i] = i;
    }
    for (int i = 1 ; i <= N ; i++) {
        for(int j = 0 ; j < adj[i].size() ;j++) {
            if(findParent(i) != findParent(adj[i][j])){
                Union(i,adj[i][j]);
            }
        }
    }
    bool f = true;
    for (int i = 0 ; i < cities.size()-1 ;i++) {
        if(findParent(cities[i]) != findParent(cities[i+1])) {
            f = false; break;
        }
    }
    if(f)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}