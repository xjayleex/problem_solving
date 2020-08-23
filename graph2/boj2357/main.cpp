#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <cassert>
using namespace std;
struct Data {
    int minValue;
    int maxValue;
};
int smaller(const int &a, const int &b){ return a < b ? a : b; }
int bigger(const int &a, const int &b){ return a > b ? a : b; }
struct IndexedTree {
    vector<Data> tree;
    vector<Data> origins;
    int leafSize, depth;

    void Init (vector<Data> &org) {
        origins = org;
        double dd = log2(origins.size()-1);
        int id = log2(origins.size()-1);
        if (dd - id == 0)
            depth = id;
        else
            depth = id + 1;

        leafSize = pow(2, this->depth);
        tree.resize((int)pow(2,depth+1), Data{INT_MAX,-1});

    }

    Data makeTree(int node, int left, int right) {
        if(left == right) {
            if(left < origins.size()) {
                //cout << "Left : " << left << ' ' << origins[left].minValue << ' ' << origins[left].maxValue << '\n';
                return tree[node] = origins[left];
            } else {
                return tree[node] = Data{INT_MAX, -1};
            }
        }


        int mid = (left + right) / 2;
        Data l = makeTree(node*2, left, mid);
        Data r = makeTree(node*2+1, mid+1, right);
        tree[node].maxValue = bigger(l.maxValue,r.maxValue);
        tree[node].minValue = smaller(l.minValue, r.minValue);
        return tree[node];
    }

    Data query(int node, int left, int right, const int &qLeft, const int &qRight) {
        if (qRight < left || right < qLeft) {
            return Data{INT_MAX, -1};
        } else if (qLeft <= left && right <= qRight) {
            return tree[node];
        } else {
            int mid = (left+right) / 2;
            Data l = query(node*2, left, mid, qLeft, qRight);
            Data r = query(node*2+1, mid+1, right, qLeft, qRight);
            return Data{
                    smaller(l.minValue,r.minValue),
                    bigger(l.maxValue, r.maxValue)
                    };
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M, a,b; cin >> N >> M;
    vector<Data> in;
    in.push_back(Data{INT_MAX,-1}) ;
    for (int i = 1 ; i <= N ; i++) {
        cin >> a;
        in.push_back(Data{a,a});
    }

    IndexedTree idxTree;
    idxTree.Init(in);

    idxTree.makeTree(1,1,idxTree.leafSize);
    /*for(int i = 0 ; i < idxTree.tree.size() ; i++) {
        cout <<'('<<idxTree.tree[i].minValue << "," << idxTree.tree[i].maxValue << ") ";
    }*/
    for (int i = 0 ; i < M ; i++ ){
        cin >> a >> b;
        if(a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        Data result = idxTree.query(1,1,idxTree.leafSize,a,b);
        cout << result.minValue << ' ' << result.maxValue << '\n';
    }
    return 0;
}