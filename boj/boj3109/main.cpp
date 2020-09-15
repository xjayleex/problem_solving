#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;
int dc[3] = {1,1,1};
int dr[3] = {-1,0,1};
int R, C;
vector <string> board;
bool visited[10000][500];
int ans = 0;
bool dfs (int r, int c ) {
    if ( c == C-1 ) {
        return true;
    }
    bool flag;
    for (int i = 0 ; i < 3 ; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if ( nr < 0 || nr >= R ) continue;
        if (visited[nr][nc]) continue;
        if (board[nr][nc] == 'x') continue;
        visited[nr][nc] = true;
        flag = dfs(nr,nc);
        if(flag) return true;
        // visited 배열을 백트래킹 안해주는 이유
        // 어떤 좌표에서 visited 되어있다는것은 이미 방문했다는 것이고, 그 좌표에서
        // 더 나아가서 해답을 구했으면 당연히 visited true 상태이고,
        // 못 나아가서 해답을 못구했으면 더이상 가볼 필요가 업으므로 visited true로 두어
        // 재탐색 되지 않도록 한다.
    }
    // 이 노드에서 더 이상 갈 수 있는 방향이 없을 때 도달.
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(visited,false,sizeof(visited));
    cin >> R >> C;
    string tmp;
    for (int i = 0; i < R ; i++) {
        cin >> tmp; board.push_back(tmp);
    }
    for (int i = 0 ; i < R ; i++) {
        if( dfs(i,0) )
            ans += 1;
    }
    cout << ans  << '\n';
    return 0;
}