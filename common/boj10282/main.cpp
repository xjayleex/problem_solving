#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int T;
int n,d,c; int a,b,s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >>T ;
    while (T--){
        cin >> n >> d >> c;
        vector<vector<pair<int,int>>> adj(n+1);
        for (int i = 0 ; i < d ; i++) {
            cin >> a >> b >> s;
            adj[b].push_back(make_pair(a,s));
        }
    }
    return 0;
}