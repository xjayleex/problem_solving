#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 100001;
vector<int> graph[MAX];
int ac[MAX][20];
int depth[MAX];
int max_level = 0;
void make_tree(int here, int parent) {
    depth[here] = depth[parent] + 1;
    ac[here][0] = parent;
    for (int i = 1; i <= max_level ; i++){
        ac[here][i] = ac[ ac[here][i-1] ][ i-1 ];
    }
    for (int i = 0 ; i < graph[here].size() ; i++) {
        int next = graph[here][i];
        if( next == parent )
            continue;
        make_tree(next,here);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    int a,b;
    cin >> N;
    vector <int> ans;
    for (int i = 0 ; i < N - 1 ; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    max_level = (int)floor(log2(MAX));
    depth[0] = -1;
    make_tree(1,0);
    cin >> M;
    for (int t = 0 ; t < M ; t++) {
        cin >> a >> b;
        if(depth[a] != depth[b]) {
            if ( depth[a] > depth[b] )
                swap(a,b);
            // depth[b] >= depth[a] 되도록
            for (int i = max_level ; i >= 0 ; i--) {
                if(depth[a] <= depth[ac[b][i]])
                    b = ac[b][i];
            }
        }
        int lca = a;
        if ( a !=  b) {
            for (int i = max_level ; i >= 0 ; i--){
                if( ac[a][i] != ac[b][i] )
                    a = ac[a][i], b = ac[b][i];
                lca = ac[a][i];
            }
        }
        ans.push_back(lca);
    }
    for (int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << '\n';
    }

    return 0;
}