#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
vector <string> board;
int ySize, xSize, N;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int groupMap[101][101];
bool visited[101][101];
bool visited1[101][101];
struct Point {
    int x,y;
};
bool compare(const Point &a, const Point &b) {
    return a.y < b.y;
}
int smaller(const int &a, const int &b) {
    return a < b ? a : b;
}

bool bfs(Point p) {
    int minDist = 101;
    memset(visited,false,sizeof(visited));
    vector<Point> mPoints;
    int color = groupMap[p.y][p.x];
    queue <Point> q; q.push(Point{p.x,p.y});
    visited[p.y][p.x] = true;
    while(!q.empty()) {
        Point now = q.front(); q.pop(); int tx = now.x, ty = now.y; int dist = 0; bool flag = true;
        mPoints.push_back(now);
        while(ty >= 1) {
            ty -= 1;
            if(groupMap[ty][tx] == color) {
                flag = false; break;
            }
            if(groupMap[ty][tx] == 0) {
                dist += 1; continue;
            } else break;
        }
        if (flag) {
            minDist = smaller(minDist, dist);
        }
        for (int k = 0 ; k < 4 ; k++) {
            int nx = now.x + dx[k], ny = now.y + dy[k];
            if(nx < 0 || ny < 0 || nx >= xSize || ny >= ySize) continue;
            if(visited[ny][nx]) continue;
            if(groupMap[ny][nx] != color) continue;
            visited[ny][nx] = true;
            q.push(Point{nx,ny});
        }
    }
    if(minDist != 0 && minDist != 101) {
        sort(mPoints.begin(), mPoints.end(), compare);
        for(Point &pp : mPoints) {
            groupMap[pp.y - minDist][pp.x] = groupMap[pp.y][pp.x]; groupMap[pp.y][pp.x] = 0;
        }
        return true;
    }
    return false;
}
void dfs (Point p, int nbr){
    groupMap[p.y][p.x] = nbr;
    visited1[p.y][p.x] = true;
    for(int k = 0 ; k < 4 ; k++) {
        int nx = p.x + dx[k];
        int ny = p.y + dy[k];
        if(nx < 0 || ny < 0 || nx >= xSize || ny >= ySize) continue;
        if(visited1[ny][nx]) continue;
        if(board[ny][nx]=='.') continue;
        dfs(Point{nx,ny},nbr);
    }
}
void chk() {
    // grouping
    bool flag = false;
    memset(visited1,false,sizeof(visited1));
    memset(groupMap,0,sizeof(groupMap));
    vector<Point> startPoints;
    int numbering = 1;
    for(int i = 0 ; i < ySize; i++) {
        for (int j = 0 ; j < xSize ; j++) {
            if(visited1[i][j]) continue;
            if(board[i][j] == '.') continue;
            startPoints.push_back(Point{j,i});
            dfs(Point{j,i},numbering++);
        }
    }
    for(int i = 0 ; i < startPoints.size() ; i++) {
        flag = bfs(startPoints[i]);
    }
    if(flag) {
        for(int i = 0 ; i < ySize ; i++) {
            string row="";
            for(int j = 0 ; j < xSize ; j++) {
                if(groupMap[i][j] == 0)
                    row += '.';
                else
                    row += 'x';
            }
            board[i] = row;
        }
    }
}

int main() {
    cin >> ySize >> xSize;
    string in; board.resize(ySize);
    for (int i = ySize - 1 ; i >= 0 ; i--) {
        cin >> board[i];
    }
    cin >> N; vector<int> sticks(N);
    for (int i = 0 ; i < N ; i++) { cin >> sticks[i]; }
    for (int i = 0 ; i < sticks.size(); i++) {
        int floor = sticks[i]-1;
        if(i % 2 == 0) {
            int nx = 0;
            while(nx < xSize){
                if(board[floor][nx]=='x'){
                    board[floor][nx] = '.'; break;
                } else { nx += 1; }
            }
        } else {
            int nx = xSize - 1;
            while(nx >= 0) {
                if(board[floor][nx]=='x'){
                    board[floor][nx] = '.'; break;
                } else { nx -= 1; }
            }
        }
        chk();
    }
    for(int fl = ySize - 1 ; fl >= 0 ; fl--) {
        cout << board[fl] << '\n';
    }
    return 0;
}