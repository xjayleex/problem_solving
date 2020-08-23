#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100001;
typedef long long ll;
int ac[MAX][20];
int maxs[MAX][20];
int mins[MAX][20];
int depth[MAX];
int max_level = 0;
vector <vector<pair<int,int>>> graph(MAX);
void make_tree(pair<int,int> here, int parent) {
    depth[here.first] = depth[parent] + 1;
    ac[here.first][0] = parent;
    mins[here.first][0] = here.second;
    maxs[here.first][0] = here.second;
    for (int i = 1 ; i <= max_level ; i++){
        ac[here.first][0] = ac[ ac[here.first][i-1] ][i-1]; // dp
    }
    for (int i = 0; i < graph[here.first].size() ;i++) {
        pair<int,int> next = graph[here.first][i];
        if(next.first == parent)
            continue;
        make_tree(next, here.first);
    }
}

void f() {
    for () {
        for () {
            ac[i][j] = ac[ ac[i][j-1] ][j-1];
        }
    }
}
int main() {
    int N, K;
    cin >> N;

    int a,b,c;
    for (int i = 1 ; i <= N - 1 ; i++) {
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }

    return 0;
}