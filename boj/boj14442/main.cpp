#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 4MB
bool visited[1001][1001][10];
struct Point {
    int x, y;
    int cost;
    int breaked;
};
int N, M, K;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K;
    vector<vector<int>> board(N,vector<int>(M,0));
    string tmp;

    for (int i = 0 ; i < N ; i++) {
        cin >> tmp;
        for(int j = 0 ; j < M ; j++) {
            if(tmp[j]=='0')
                board[i][j] = 0;
            else
                board[i][j] = 1;
        }
    }
    queue <Point> queue;
    queue.push(Point{0,0,1,0});
    visited[0][0][0] = true;
    while(!queue.empty()){
        Point now = queue.front(); queue.pop();
        if (now.x == M-1 && now.y == N-1){
            cout << now.cost << '\n';
            return 0;
        }
        for (int k = 0 ; k < 4 ; k++) {
            int nx = now.x + dx[k];
            int ny = now.y + dy[k];
            if (nx < 0 || ny <0 || nx >= M || ny >= N)
                continue;
            if(visited[ny][nx][now.breaked])
                continue;
            if (board[ny][nx] == 1){
                if (now.breaked+1 <= K) {
                    visited[ny][nx][now.breaked+1] = true;
                    queue.push(Point{nx,ny,now.cost+1,now.breaked+1});
                }
            } else {
                visited[ny][nx][now.breaked] = true;
                queue.push(Point{nx,ny,now.cost+1,now.breaked});
            }
        }
    }
    cout << "-1" << '\n';
    return 0;
}