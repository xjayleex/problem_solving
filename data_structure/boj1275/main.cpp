#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
typedef long long ll;
struct IndexedTree {
    vector<ll> tree;
    vector<ll> inputs;
    int leafSize, depth;

    void Init(vector<ll> inputs) {
        this->inputs = inputs;
        double dd =log2(inputs.size()-1);
        int id = log2(inputs.size()-1);
        if (dd - id == 0)
            this->depth = id;
        else {
            this-> depth = id + 1;
        }
        this->leafSize = pow(2,this->depth);
        tree.resize((int)pow(2,this->depth+1));
    }

     ll makeTree(int node, int left, int right) {
        if(left == right) {
            if (left <= inputs.size())
                return tree[node] = inputs[left];
            else return tree[node] = 0;
        }
        int mid = (left+right) / 2;
        tree[node] += makeTree(node*2, left,mid) + makeTree(node*2+1,mid+1,right);
        return tree[node];
    }

    ll query(int node, int left, int right, int qLeft, int qRight) {
        if (qRight < left || right < qLeft) {
            return 0;
        } else if (qLeft <= left && right <= qRight) {
            return tree[node];
        } else {
            int mid = (left + right) / 2;
            return query(node*2, left, mid, qLeft, qRight) + query(node*2 +1, mid+1, right,qLeft,qRight);
        }
    }
    void update(int node, int left, int right, int index, ll diff) {
        if (index < left || right < index) {
            return;
        } else {
            tree[node] += diff;
            if (left != right) {
                int mid = (left + right) / 2;
                update(node * 2, left, mid ,index, diff);
                update(node * 2 + 1, mid + 1, right, index ,diff);
            }
        }
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,Q;
    cin >> N >> Q;
    vector<ll> in(N+1); in[0] = 0;
    for (int i = 1 ; i <= N ; i++) {
        cin >> in[i];
    }
    IndexedTree idxTree;
    idxTree.Init(in);
    idxTree.makeTree(1,1,idxTree.leafSize);
    int x,y,a,b;
    for(int i = 0 ; i < Q ; i++) {
        cin >> x >> y >> a >> b;
        if (x > y) {
            int tmp;
            tmp = y;
            y = x ;
            x = tmp;
        }
        cout << idxTree.query(1,1,idxTree.leafSize,x,y) << '\n';
        ll diff = b - idxTree.inputs[a];
        idxTree.update(1,1,idxTree.leafSize,a, diff);
        idxTree.inputs[a] = b;
    }
    return 0;
}