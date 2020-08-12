#include <iostream>
#include <vector>
using namespace std;
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
// https://www.geeksforgeeks.org/segment-tree-efficient-implementation/
// 위 구현으로 안풀리는 문제가 있어서, 다음과 같이 재귀적인 구현 필요.
typedef long long ll;
struct IndexedTree {
    vector<ll> tree;
    vector<ll> nums;
    int leafSize, depth;

    void Init (vector<ll> ns) {
        nums = ns;
        double d = log2(ns.size()-1);
        int dd = log2(ns.size()-1);
        if (d-dd == 0) {
            this->depth = dd;
        } else {
            this->depth = dd + 1;
        }
        this->leafSize = pow(2,this->depth);
        tree.resize((int)pow(2,depth+1));
    }
    ll makeTree(int node, int left, int right) {
        // 리프에 도달하면 데이터를 채워줌
        if(left == right) {
            if(left <= nums.size() ){ //
                return tree[node] = nums[left];
            } else {
                return tree[node] = 0;
            }
        }
        // 내부 노드일 경우
        int mid = (left + right) / 2;
        tree[node] = makeTree(node * 2, left, mid);
        tree[node] += makeTree(node * 2 + 1, mid +1, right);
        return tree[node];
    }
    ll query(int node, int left, int right, int qLeft, int qRight){
        if(qRight < left || right < qLeft) { // 관련 없는 케이스
            return 0;
        } else if (qLeft <= left && right <= qRight) { //쿼리에 완전 속하는 경우
            return tree[node];
        } else { // 애매하게 걸쳐있는 경우 ?
            int mid = (left + right) /2;
            return query(node * 2, left ,mid, qLeft, qRight) + query(node * 2 + 1, mid + 1, right, qLeft, qRight);
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    vector <ll> nums(N+1);
    nums[0] = 0;
    for(int i = 1 ; i <= N ; i++){
        cin >> nums[i];
    }
    IndexedTree idxTree;
    idxTree.Init(nums);
    idxTree.makeTree(1,1,idxTree.leafSize);
    /*for(int i = 0 ; i < idxTree.tree.size() ; i++) {
        cout << idxTree.tree[i] << ' ';
    }
    cout << "\n-------------------------------" << '\n';
    while(true){
        int a,b;
        cin >> a >> b;
        cout << idxTree.query(1,1,idxTree.leafSize,a,b) << endl;}*/
    int a,b,c;
    for(int i = 0 ; i < M + K ; i++) {
        cin >> a >> b >> c ;
        if( a == 1 ) {
            ll diff = c - idxTree.nums[b];
            idxTree.update(1,1,idxTree.leafSize,b,diff);
            idxTree.nums[b] = c;
        } else {
            if (b > c) {
                int tmp;
                tmp = c;
                c = b;
                b = tmp;
            }
            cout << idxTree.query(1,1,idxTree.leafSize,b,c)<<'\n';
        }
    }
    return 0;
}