#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
// https://www.geeksforgeeks.org/segment-tree-efficient-implementation/
// 위 구현으로 안풀리는 문제가 있어서, 다음과 같이 재귀적인 구현 필요.
struct IndexedTree {
    vector<int> tree;
    vector<int> nums;
    int leafSize, depth;

    void Init (vector<int> ns) {
        nums = ns;
        double d = log2(ns.size());
        this->depth = log2(ns.size());
        this->leafSize = pow(2,this->depth);
        tree.resize((int)pow(2,depth+1));
    }
    int makeTree(int node, int left, int right) {
        // 리프에 도달하면 데이터를 채워줌
        if(left == right) {
            if(left <= nums.size() - 1){ // -1 ?
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
    int query(int node, int left, int right, int qLeft, int qRight){
        if(qRight < left || right < qLeft) { // 관련 없는 케이스
            return 0;
        } else if (qLeft <= left && right <= qRight) { //쿼리에 완전 속하는 경우
            return tree[node];
        } else { // 애매하게 걸쳐있는 경우 ?
            int mid = (left + right) /2;
            return query(node * 2, left ,mid, qLeft, qRight) + query(node * 2 + 1, mid + 1, right, qLeft, qRight);
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
    vector<int> nums {
        0,3,2,4,5,1,6,2,7,
    };
    IndexedTree indexedTree;
    indexedTree.Init(nums);
    cout << "depth : " << indexedTree.depth << "  leafSize : " << indexedTree.leafSize <<
    "  treeSize : " << indexedTree.tree.size() <<'\n';
    indexedTree.makeTree(1,1,indexedTree.leafSize);
    for(int i = 0 ; i < indexedTree.tree.size() ; i++) {
        cout << indexedTree.tree[i] << ' ';
    }
    cout << "\n-------------------------------" << '\n';

    int targetIndex = 3;
    int targetValue = 3;
    int diff = targetValue - indexedTree.nums[targetIndex];
    indexedTree.update(1,1,indexedTree.leafSize, targetIndex, diff);
    indexedTree.nums[targetIndex] = targetValue;
    for(int i = 0 ; i < indexedTree.tree.size() ; i++) {
        cout << indexedTree.tree[i] << ' ';
    }
    cout << "\n-------------------------------" << '\n';

    return 0;
}