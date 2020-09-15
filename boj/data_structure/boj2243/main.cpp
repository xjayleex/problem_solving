#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
const int MAX = 1000001;
//const int MAX = 33;
struct IndexedTree {
    vector<int> tree;
    vector<int> origin;
    int leafSize;
    int depth;
    void Init() {
        double dd =log2(MAX-1);
        int id = log2(MAX-1);
        if (dd - id == 0) {
            this->depth = id;
        } else
            this->depth = id + 1;
        this->leafSize = pow(2,depth);
        tree.resize((int)pow(2,depth+1));
        origin.resize(MAX);
        origin[0] = 0;
    }
    // n번째에 해당하는 맛있는 사탕이 몇번째 index에 해당하는지 알려줌.
    int query(int node, int left, int right, int rank) {
        if(left == right) {
            return node;
        }
        int mid = (left + right) / 2;

        if ( tree[node*2] + 1 <= rank && rank <= tree[node]) {// left  mid ;
            //cout << "Tree[node*2]+1 : " << tree[node*2]+1 << "  Rank : "<< rank <<'\n';
            return query(node*2+1, mid + 1 , right ,rank - tree[node*2]);
        } else {
            return query(node*2, left, mid, rank);
        }
    }
    void update(int node, int left, int right, int index, int diff) {
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
    /*int a = log2(1000001) + 1;
    cout << "depth : "<< a << '\n';
    cout << "leafsize : " << (int)pow(2,a) << '\n';
    cout << "treesize : " << (int)pow(2,a+1) << '\n';*/
    ios_base::sync_with_stdio(0); cin.tie(0);
    IndexedTree idxTree;
    idxTree.Init();
    int queryCnt;
    int A,B,C;
    cin >> queryCnt;
    for (int i = 0 ; i < queryCnt ; i++) {
        cin >> A;
        if( A == 1 ) { // B에 해당하는 사탕을 query로 index를 알아내서 index tree update 해줘야함.
            // 한개의 사탕을 꺼낸다.
            cin >> B;
            int target = idxTree.query(1,1,idxTree.leafSize,B) - idxTree.leafSize + 1;
            idxTree.update(1,1,idxTree.leafSize,target,-1);
            idxTree.origin[target] -= 1;
            cout << target << '\n';
            /*cout << "Target : " << target << '\n';
            for (int i = 0 ; i < idxTree.tree.size() ; i++) {
                cout << idxTree.tree[i] << ' ';
            }
            cout <<'\n';*/
        } else {  // 맛이 B인 사탕을 C에 ++, C < 0 이면 빼준다.
            cin >> B >> C;
            idxTree.origin[B] += C;
            idxTree.update(1,1,idxTree.leafSize,B,C);
            /*for (int i = 0 ; i < idxTree.tree.size() ; i++) {
                cout << idxTree.tree[i] << ' ';
            }
            cout <<'\n';*/
        }
    }
    return 0;
}