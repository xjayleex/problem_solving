#include <iostream>
#include <vector>
using namespace std;
int parent[1000001];

int findRoot(int x) {
    if(parent[x] == x)
        return x;
    return parent[x] = findRoot(parent[x]);
}
void Union(int x, int y) {
    int x_root = findRoot(x);
    int y_root = findRoot(y);
    parent[y_root] = x_root;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m;
    int a,b,c;
    cin >> n >> m;
    for (int i = 0 ; i <=n ; i++){
        parent[i] = i;
    }
    for (int i = 0 ; i < m ; i++) {
        cin >> a >> b >> c;
        if(a == 0) {
            if (b > c)
                Union(c,b);
            else
                Union(b,c);
        } else {
            if(findRoot(b) == findRoot(c))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }
    return 0;
}