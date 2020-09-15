#include <iostream>
#include <vector>
using namespace std;
typedef long long llong;
const int N_MAX = 100000+1;
int parents[N_MAX];
llong diff_weights[N_MAX];
int Update(int x) {
    if(parents[x] == x)
        return x;
    // return parents[x] = Update(parents[x]);
    // equals
    int prev = Update(parents[x]);
    diff_weights[x] += diff_weights[parents[x]];
    return parents[x] = prev;
}

void Union(int s, int b, llong w) {
    int s_root = parents[s];
    int b_root = parents[b];
    if (s_root == b_root)
        return;
    parents[b_root] = s_root;

}
void doMeasure(int s_one, int b_one, llong weight) {

}
int Init(const int &n){
    for(int i = 1 ; i <= n ; i++) {
        parents[i] = i;
    }
    for(int i = 1 ; i <= n ; i++) {
        diff_weights[i] = 0;
    }
}
int main() {
    Init(6);
    Union(1,2,100);
    Union(3,4,-150);
    Union(1,3,20);
    /*ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int f,s, a, b;
    llong w;
    char opt;

    while(true) {
        cin >> f >> s;
        if(f == 0 && s == 0)
            break;
        Init(N_MAX-1);
        for(int i = 0 ; i < s ; i++) {
            cin >> opt;
            if(opt == '!') {
                cin >> a >> b >> w;
                doMeasure(a,b,w);
            } else {
                cin >> a >> b;
            }
        }
    }*/
    return 0;
}