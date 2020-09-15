#include <iostream>
#include <vector>
using namespace std;
int N,M;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
struct CCTV {
    int x;
    int y;
    int rotate;
    vector<int> dir;
    void setBasicDirection(int spec) {
        dir.push_back(0);
            if (spec == 1) {
                rotate = 4;
            }
            else if (spec == 2) {
                dir.push_back(2);
                rotate = 2;
            }
            else if (spec == 3) {
                dir.push_back(3);
                rotate = 4;
            }
            else if (spec == 4){
                dir.push_back(2);
                dir.push_back(3);
                rotate = 4;
            }
            else if (spec == 5)  {
                dir.push_back(1);
                dir.push_back(2);
                dir.push_back(3);
                rotate = 1;
            }
        }

};
int ans = 8 * 8 + 1;
int smaller(const int &a, const int &b) {
    return a < b ? a : b;
}
void draw(const int &cidx, vector<CCTV> &cctv,vector<vector<int>> &board){
    int x = cctv[cidx].x, y = cctv[cidx].y;

    for (int i = 0 ; i < cctv[cidx].dir.size() ; i++) {
        int nx = x, ny = y;
        while(true) {
            nx = nx + dx[ cctv[cidx].dir[i] ];
            ny = ny + dy[ cctv[cidx].dir[i] ];
            if(nx < 0 || ny < 0 || nx >= M || ny >= N)
                break;
            if(board[ny][nx] == -1)
                break;
            if(board[ny][nx] == 1)
                continue;
            board[ny][nx] = 1;
        }
    }
}
void rotate(CCTV &cElem) {
    for(int i = 0 ; i < cElem.dir.size() ; i++) {
        cElem.dir[i] = (cElem.dir[i] + 1)% 4;
    }
}
int check(const vector<vector<int>> &board) {
    int zeroCnt = 0;
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            if(board[i][j] == 0)
                zeroCnt += 1;
        }
    }
    return zeroCnt;
}
void dfs(vector<CCTV> cctv, int cidx, vector<vector<int>> board){
    if(cidx == cctv.size()) {
        ans = smaller(ans,check(board));
        return;
    }
    vector<vector<int>> copied;
    for (int d = 0 ; d < cctv[cidx].rotate; d++){
        copied = board;
        draw(cidx,cctv,copied);
        dfs(cctv,cidx+1,copied);
        rotate(cctv[cidx]);
    }
}
int main() {

    cin >> N >> M;
    vector<vector<int>> board(N,vector<int>(M,0));
    vector <CCTV> cctv;
    int a, wallCnt = 0;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ;j++) {
            cin >> a;
            if(a == 6) {
                board[i][j] = -1;
                wallCnt += 1;
            } else if (a == 0){ // 사각지대.
                board[i][j] = 0;
                continue;
            } else {
                CCTV tmp;
                tmp.y = i, tmp.x = j;
                tmp.setBasicDirection(a);
                board[i][j] = 1;
                cctv.push_back(tmp);
            }
        }
    }
    if(cctv.size() == 0) {
        cout << N * M - wallCnt << '\n';
        return 0;
    }
    dfs(cctv,0,board);
    cout << ans << '\n';

    return 0;
}