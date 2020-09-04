#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
struct Data {
    int odd;
    int even;
};
struct IndexedTree {
    vector<int> origins;
    vector<Data> tree;
    int leafSize, depth;

    void Init (vector<int> &org) {
        origins = org;
        double dd = log2(origins.size()-1);
        int id = log2(origins.size()-1);
        if(dd-id==0)
            depth = id;
        else
            depth = id + 1;
        leafSize = pow(2,this->depth);
        tree.resize((int)pow(2,depth+1));
    }

    Data makeTree(int node, int left, int right) {
        if(left==right) {
            if (left < origins.size()) {
                if(origins[left] % 2 == 0)
                    return tree[node] = Data{0,1};
                else
                    return tree[node] = Data{1,0};
            } else {
                return tree[node] = Data{0,0};
            }
        }
        int mid = (left+right)/2;
        Data l = makeTree(node*2, left,mid);
        Data r = makeTree(node*2+1,mid+1,right);
        tree[node].even = l.even + r.even;
        tree[node].odd = l.odd + r.odd;
        return tree[node];
    }

    Data query(int node, int left, int right, int qLeft, int qRight) {
        if(qRight < left || right < qLeft)
            return Data{0,0};
        if(qLeft <= left && right <= qRight){
            return tree[node];
        } else {
            int mid = (left + right) / 2;
            Data l = query(node*2, left, mid, qLeft, qRight);
            Data r = query(node*2+1, mid+1, right, qLeft, qRight);
            return Data{l.odd+r.odd,l.even+r.even};
        }
    }

    void update(int node, int left, int right, int index, bool oddToEven) {
        if (index < left || right < index) {
            return;
        } else {
            if(oddToEven) {
                tree[node].even += 1;
                tree[node].odd -= 1;
            } else {
                tree[node].even -= 1;
                tree[node].odd += 1;
            }
            if(left != right) {
                int mid = (left + right) / 2;
                update(node*2, left, mid, index, oddToEven);
                update(node*2+1,mid+1,right,index,oddToEven);
            }
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,t; cin >> N;
    vector<int> org; org.push_back(0);
    for (int i = 0 ; i < N ; i++) {
        cin >> t;
        org.push_back(t);
    }
    IndexedTree idxTree; idxTree.Init(org); idxTree.makeTree(1, 1, idxTree.leafSize);
    /*for(int i = 0 ; i < idxTree.tree.size(); i++) {
        cout << "(" << idxTree.tree[i].odd << ", " <<  idxTree.tree[i].even << ") ";
    }
    cout << '\n';*/
    int q; cin >> q;
    int a,b,c;
    for(int i = 0 ; i < q ; i++) {
        cin >> a >> b >> c;
        if(a == 1) {
            if( c % 2 == 0) { // even
                if(idxTree.origins[b]%2 == 1) { // odd
                    idxTree.update(1,1,idxTree.leafSize,b,true);
                }
            } else { // odd
                if(idxTree.origins[b]%2==0) { // even
                    idxTree.update(1,1,idxTree.leafSize,b,false);
                }
            }
            idxTree.origins[b] = c;
        } else if (a==2) {
            Data d = idxTree.query(1,1,idxTree.leafSize,b,c);
            cout << d.even << '\n';
        } else {
            Data d = idxTree.query(1,1,idxTree.leafSize,b,c);
            cout << d.odd << '\n';
        }
    }
    return 0;
}