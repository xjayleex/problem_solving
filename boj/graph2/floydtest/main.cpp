#include <iostream>
#include <climits>
using namespace std;
const int INF = 98765321;
int adj[101][101];
int smaller(int a, int b){
    return a > b ? b :a ;
}
int main() {
    int n,m;
    cin >> n;
    cin >> m;
    int src,dst,weight;
    for(int i = 0 ; i < m;i++){
        cin >> src >> dst >> weight;
        if(adj[src][dst] != 0){
            adj[src][dst] = smaller(adj[src][dst], weight);
        }
        else {
            adj[src][dst] = weight;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(adj[i][j] == 0){
                adj[i][j] = INF;
            }
            if(i == j){
                adj[i][j] = 0;
            }
        }
    }
    for(int k = 1 ; k <= n ; k++){
        for(int i = 1; i <= n ; i++){
            if (adj[i][k] == INF)
                continue;
            for(int j = 1 ; j <= n ; j++){
                adj[i][j] = smaller(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
    for(int i =1 ; i <= n ; i++){
        for(int j = 1; j<=n ;j++){
            if(adj[i][j] == INF ){
                cout << "0" << ' ';
            }
            else {
                cout << adj[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}