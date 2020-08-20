
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstdio>
using namespace std;
struct Edge {
    int src;
    int dst;
};
vector <bool> ans;
vector <Edge> edges;

bool doTreeCheck (int n) {
    /*for (int i = 0 ; i < edges.size(); i++){
        cout << edges[i].src << " --> " << edges[i].dst <<'\n';
    }*/
    if (edges.size() == 0)
        return false;
    vector <vector<int>> adj(n);
    bool visited[n];
    unordered_map <int,int> dstMap;
    unordered_map<int,int>::iterator iter;
    for (int i = 0 ; i < edges.size() ; i++){
        dstMap[edges[i].dst] += 1;
        adj[edges[i].src].push_back(edges[i].dst);
    }
    int noIncomingEdgeCnt = 0; int root = -1;
    bool IncomingEdgeNodeCheck[n];
    for( iter = dstMap.begin(); iter != dstMap.end() ; iter++) {
        if ( (*iter).second > 1 ) {
            //cout << "incoming Edge is over >= 1"  << '\n';
            return false;
        }
        IncomingEdgeNodeCheck[(*iter).first] = true;
    }
    for (int i = 0 ; i < n ; i++) {
        if(!IncomingEdgeNodeCheck[i]) {
            root = i;
            noIncomingEdgeCnt +=1;
            //cout << i << ' ';
        }
    }

    if (noIncomingEdgeCnt != 1){
        //cout << "no incoming edge Node are not !=1 " << '\n';
        return false;
    }
    queue <int> q;
    q.push(root);
    visited[root] = true;
    while(!q.empty()) {
        int current = q.front(); q.pop();
        for(int i = 0; i < adj[current].size() ;i++) {
            if(visited[adj[current][i]])
                continue;
            q.push(adj[current][i]);
            visited[adj[current][i]] = true;
        }
    }
    for (int i = 0 ; i < n ; i++) {
        if(!visited[i]) {
            //cout << "unvisited node Exists." << '\n';
            return false;
        }
    }
    return true;
}
int main() {
    int foo,bar, src, dst, numbering = 0;
    unordered_map <int,int> mp;
    unordered_map <int,int>::iterator iter;
    while(true){
        scanf("%d %d", &foo, &bar);
        if (foo == -1 && bar == -1) {
            break;
        } else if (foo == 0 && bar == 0) {

            ans.push_back(doTreeCheck(numbering));
            edges.clear();
            mp.clear();
            numbering = 0;
        } else {
            if(mp.find(foo) == mp.end()) {
                src = numbering++;
                mp[foo] = src;
            } else {
                src = mp[foo];
            }
            if(mp.find(bar) == mp.end()){
                dst = numbering++;
                mp[bar] = dst;
            } else {
                dst = mp[bar];
            }
            edges.push_back(Edge{src,dst});
        }
    }
    for (int i = 0 ; i < ans.size() ;i++){
        if ( ans[i] ) {
            printf("Case %d is a tree.\n",i+1);
        } else {
            printf("Case %d is not a tree.\n",i+1);
        }
    }
    return 0;
}