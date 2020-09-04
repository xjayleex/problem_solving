#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int N,d;
int bigger (const int &a, const int &b){
    return a > b ? a : b;
}
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int bfs(const vector<vector<int>> &b, int ix, int iy){
    int cnt = 0;
    vector<vector<int>> board = b;
    vector<vector<bool>> visited(N, vector<bool>(N,false));
    queue<tuple<int,int,int>> q;
    q.push(make_tuple(ix,iy,0));
    int x,y,numbering;
    while(!q.empty()) {
        tie(x,y,numbering) = q.front(); q.pop();
        if(visited[y][x])
            continue;
        else {
            cnt += 1;
            visited[y][x] = true;
            board[y][x] = numbering;
        }
        for (int k = 0 ; k < 4 ; k++) {
            int nx = x + dx[k]; int ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                continue;
            if (board[ny][nx] == -1)
                continue;
            if (visited[ny][nx])
                continue;
            if (numbering + 1 > d)
                continue;
            q.push(make_tuple(nx,ny,numbering+1));
        }
    }
    return cnt;
}
int main() {
    int ans = 0;
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> d; int tmp;
    vector<vector<int>> board(N, vector<int>(N,0));
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0; j < N ;j ++) {
            cin >> tmp;
            if (tmp == 0){
                board[i][j] = 0;
            } else {
                board[i][j] = -1;
            }
        }
    }
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0; j < N ;j ++) {
            int localAns = 0;
            if(board[i][j] == 0) {
                localAns = bfs(board,j,i);
            }
            ans = bigger(ans,localAns);
        }
    }
    cout << ans << '\n';
    return 0;
}