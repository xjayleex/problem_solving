#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;
int bigger(int a, int b) {
    return a > b ? a : b;
}
struct IndexedTree {
    vector <int> tree;
    vector <int> inputs;
    int leafSize, depth;

    void Init (vector<int> inputs) {
        this->inputs = inputs;
        double dd = log2(inputs.size()-1);
        int id = log2(inputs.size()-1);
        if (dd-id == 0)
            this->depth= id;
         else {
             this->depth = id + 1;
         }
         this->leafSize = pow(2,this->depth);
         tree.resize((int)pow(2,depth+1));
    }
    int makeTree(int node, int left, int right) {
        if (left == right){
            if (left <= inputs.size()) {
                return tree[node] = inputs[left];
            } else
                return tree[node] = 0;
        }
        int mid = (left + right) / 2;
        tree[node] = bigger(makeTree(node*2,left,mid), makeTree(node*2+1,mid+1,right));
        return tree[node];
    }
    int query(int node, int left, int right, int qLeft, int qRight) {
        if(qRight < left || right < qLeft){
            return -1;
        } else if (qLeft <= left && right <= qRight) {
            return tree[node];
        } else {
            int mid = (left + right) / 2;
            int a = query(node *2, left, mid, qLeft, qRight);
            int b = query(node*2+1,mid+1,right, qLeft,qRight);
            if ( a == -1 && b == -1) {
                return -1;
            } else if ( a == -1 ){
                return b;
            } else if ( b == -1) {
                return a;
            } else {
                return a > b ? a : b;
            }
        }
    }
};
int main() {
    int N,a,b,M;
    vector<int> amounts;
    unordered_map<int,int> mp;
    vector<int> years;
    amounts.push_back(0);
    years.push_back(0);
    cin >> N;
    for (int i = 1 ; i <= N ; i++) {
        cin >> a >> b;
        amounts.push_back(b);
        years.push_back(a);
        //mp[a] = i;
    }
    IndexedTree idxTree;
    idxTree.Init(amounts);
    idxTree.makeTree(1,1,idxTree.leafSize);
    cin >> M;
    int y,x;
    for (int i = 0 ; i < M ; i++) {
        bool maybe = false;
        cin >> y >> x;
        int y_lb_idx = lower_bound(years.begin(),years.end(),y) - years.begin();
        int x_lb_idx = lower_bound(years.begin(),years.end(),x) - years.begin();
        bool y_exists = years[y_lb_idx] == y ? true : false;
        bool x_exists = years[x_lb_idx] == x ? true : false;
        if (y_exists && x_exists) {
            //cout << "Y(O) / X(O)" << '\n';
        } else if (!y_exists && !x_exists) {
            //cout << "Y(X) / X(X)" << '\n';
        } else if (!y_exists && x_exists) {
            //cout << "Y(X) / X(O)" << '\n';
        } else if (y_exists && !x_exists) {
            //cout << "Y(O) / X(X)" << '\n';
        }
    }
    /*unordered_map<int,int>::iterator ia;
    unordered_map<int,int>::iterator ib;
    for (int i = 0 ; i < M ; i++) {
        cin >> a >> b;
        ia = mp.find(a); ib = mp.find(b);
        if ( ia == mp.end() ) {
            // not found

        } else {
            // found
            [(*ia).second]
        }

        if ( ib == mp.end() ) {

        } else {

        }
    }*/

    return 0;
}