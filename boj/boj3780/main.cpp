#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
int N, I, J;
int parents[20001];
int dists[20001];
int abs(const int &a, const int &b){
    if ( a > b)
        return a - b;
    else
        return b - a;
}
int findParent(int x) {
    if(parents[x] == x)
        return x;
    int xRoot = findParent(parents[x]);
    dists[x] += dists[parents[x]];
    return parents[x] = xRoot;
}

void Union(int x, int y) {
    dists[x] = abs(y-x)%1000;
    parents[x] = y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T; char opt;
    while(T--) {
        cin >> N;
        for(int s = 0 ; s <= N ; s++ ) { parents[s] = s; }
        memset(dists,0,sizeof(dists));
        while(true) {
            cin >> opt;
            if(opt == 'O') {
                break;
            } else if (opt == 'I') {
                cin >> I >> J;
                Union(I,J);
            } else { // opt == 'E'
                cin >> I;
                findParent(I);
                cout << dists[I] << '\n';
            }
        }
    }
    return 0;
}