#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge{
    int u, v, weight;
    Edge(int u, int v ,int weight){
        this->u = u;
        this->v = v;
        this->weight = weight;
    }
};
bool compare(const Edge &a, const Edge &b){
    return a.weight < b.weight;
}
int parent[1001];

int findRoot(int x){
    if(parent[x] == x)
        return x;
    else {
        return parent[x] = findRoot(parent[x]);
    }
}
int Union(int x, int y){
    int x_root= findRoot(x);
    int y_root = findRoot(y);
    parent[y_root] = x_root;
}

int main() {
    int V, E;
    cin >>V >>E;
    vector <Edge> edge;
    for(int i = 0 ; i < E ; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edge.push_back({u,v,w});
    }
    sort(edge.begin(),edge.end(),compare);
    for(int i = 1; i<=V ; i++){
        parent[i] = i;
    }
    int ans = 0;
    for(int i = 0 ; i < edge.size() ; i++){
        if(findRoot(edge[i].u) == findRoot(edge[i].v))
            continue;
        Union(edge[i].u,edge[i].v);
        ans += edge[i].weight;
    }
    cout << ans << '\n';


    return 0;
}