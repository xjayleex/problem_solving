#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
typedef long long ll;
vector<int> in;
struct IndexedTree {
    int leafSize, depth;
    vector <int> origins;
    vector <int> tree;
    void Init (vector<int> in) {
        origins = in;
        double dd = log2(origins.size()-1);
        int id = log2(origins.size()-1);
        if( dd - id == 0 ) {
            depth = id;
        } else {
            depth = id + 1;
        }
        leafSize = pow(2, depth);
        tree.resize((int)pow(2,depth+1));
    }
    void makeTree(const int &node,const int &left, const int &right) {
        if (left == right) {
            if(left < origins.size()) {
                tree[node]= left;
            } else {
                tree[node] = 0;
            }
            return;
        }
        int mid = (left+right) / 2;
        makeTree(node*2, left, mid);
        makeTree(node*2+1 ,mid+1, right);
        if ( origins[tree[node * 2]] <= origins[tree[node*2+1]]) {
            tree[node] = tree[node * 2];
        }
        else {
            tree[node] = tree[node * 2 + 1];
        }
    }

    int query(const int &node, const int &left, const int &right, const int &qLeft, const int &qRight) {
        if(qRight < left || right < qLeft) {
            return -1;
        }
        if(qLeft <= left && right <= qRight) {
            return tree[node];
        }
        int mid = (left+right) / 2;
        int l = query(node*2, left, mid, qLeft, qRight);
        int r = query(node*2+1, mid+1, right, qLeft, qRight);
        if ( l == -1 ) {
            return r;
        }
        if ( r == -1 ) {
            return l;
        }
        if (origins[l] <= origins[r]) {
            return l;
        } else {
            return r;
        }
    }
    ll getMax(const int &start,const int &end) {
        int m = query(1,1,origins.size()-1,start,end);
        ll area = (ll)(end-start + 1) * (ll)origins[m];
        if (start <= m - 1) {
            ll tmp = getMax(start,m-1);
            if(tmp > area)
                area = tmp;
        }
        if ( m+1 <= end) {
            ll tmp = getMax(m+1, end);
            if(tmp > area)
                area = tmp;
        }
        return area;
    }

};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N;
    while(true) {
        cin >> N;
        if (N == 0)
            break;
        in.resize(N+1); in[0] = INT_MAX;
        for (int i = 1 ; i <= N ; i++){
            cin >> in[i];
        }
        IndexedTree idxTree;
        idxTree.Init(in);
        idxTree.makeTree(1,1,idxTree.leafSize);
        ll localAns = idxTree.getMax(1,idxTree.origins.size()-1);
        cout << localAns << '\n';
        /*for(int i = 0 ; i < idxTree.tree.size() ; i++) {
            cout << '('<< idxTree.tree[i].len <<"," << idxTree.tree[i].index <<"," << idxTree.origins[idxTree.tree[i].index] << ") ";
        }
        while(true) {
            cin >> a >> b;
            Data data = idxTree.query(1,1,idxTree.leafSize,a,b);

        }*/
    }
    return 0;
}