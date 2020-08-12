#include <iostream>
#include <vector>
using namespace std;

int arr[10010];
int n = 0;
// 전위순회 결과에서 첫번째 노드는 항상 루트다.
// 후위순회에서 루트는 항상 마지막에 출력되는데,
// 이진검색트리에서 루트 보다 작은것은 왼쪽, 큰것은 오른쪽에 위치하므로,
// 루트보다 작은 값들이 있는 구간을 먼저 출력한다.
void dfs(int l,int r) {
    if (l > r)
        return;
    int root = l;
    int s = l ,e = r;
    while(arr[s] >= arr[root])
        s++;
    while(arr[e] > arr[root])
        e--;
    dfs(s,e);
    dfs(e+1,r);
    printf("%d\n",arr[root]);
}

int main() {
    int x;
    while(scanf("%d",&x) != -1) {
        arr[n++] = x;
    }
    dfs(0,n-1);
    return 0;
}
