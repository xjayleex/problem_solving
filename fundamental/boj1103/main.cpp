#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;
// memo[Y][X], (y,x)에서는 최대 Value 번 move 가능
#define SIZE 50
int N, M;
int memo[SIZE][SIZE];
int board[SIZE][SIZE];
bool visited[SIZE][SIZE];
int dx[4]= {-1,1,0,0};
int dy[4]= {0,0,1,-1};
void getInput(){
    cin >> N >> M;
    for (int i = 0; i < N ; i++){
        string tmp;
        cin >> tmp;
        for (int j = 0 ; j < M ; j++){
            if (tmp[j] == 'H') {
                board[i][j] = 0;
            } else {
                board[i][j] = tmp[j] - '0';
            }
        }
    }
    memset(memo,-1,sizeof(memo));
}
int bigger(const int &a, const int &b){
    return a > b ? a : b;
}
int dfs(int y, int x) {
    // board range, Hole Check
    if(x < 0 || y < 0 || y >= N || x >= M || board[y][x] == 0)
        return 0;
    // If Cycle exists -> return -1 and exit;
    if(visited[y][x]){
        cout << "-1" << '\n';
        exit(0);
    }
    if (memo[y][x] != -1)
        return memo[y][x];

    int current = board[y][x];
    visited[y][x] = true;
    memo[y][x] = 0;
    for(int i = 0 ; i < 4 ; i++){
        //if(board[y+dy[i]][x+dx[i]] == 0 )
        //    continue;
        int nx = x + dx[i] * current;
        int ny = y + dy[i] * current;
        memo[y][x] = bigger(memo[y][x], dfs(ny,nx) + 1);
        // 다음 위치 (ny,nx)에 대한 dfs의 결과로서 얻은 메모이제이션 + 1(현재 위치에서 한번 이동시켰으므로 +1)과
        // 각 방향에 대한 메모이제이션을 비교해서 큰 것 저장
    }
    visited[y][x] = false; // *****important*****
    // 각각의 노드를 방문할때마다 경로는 달라진다. 다른 경로에서 같은 노드를 방문할 수 있으므로,
    // flag를 off 해준다.
    return memo[y][x];
}
int main() {
    getInput();
    int ans = dfs(0,0);
    cout << ans << '\n';
    return 0;
}