#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int N;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int bigger(const int &a, const int &b) {
    return a > b ?  a: b;
}
int main() {
     cin >> N;
    int tmp;
    int ans = 0;
    vector<vector<int>> board(N, vector<int>(N,0));
    vector<vector<int>> water(N, vector<int>(N,0));
    vector<vector<int>> person(N, vector<int>(N,0));

    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            cin >> tmp;
            if(tmp == 0) {
                board[i][j] = 0;
                water[i][j] = 0;
                person[i][j] = 0;
            }
            else if (tmp == 1) {
                board[i][j] = -1;
                water[i][j] = -1;
                person[i][j] = -1;
            }
        }
    }


    queue <tuple<int,int,int>> wq;
    wq.push(make_tuple(0,0,0));
    int x,y,numbering;
    vector<vector<bool>> visited(N, vector<bool>(N,false));
    while(!wq.empty()) {
        tie(x,y,numbering) = wq.front();
        wq.pop();
        if(visited[y][x])
            continue;
        else {
            visited[y][x] = true;
            water[y][x] = numbering;
        }
        for(int k = 0 ; k < 4 ; k++) {
            int nx = x + dx[k]; int ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                continue;
            if (water[ny][nx] == -1) {
                continue;
            }
            if (visited[ny][nx])
                continue;
            wq.push(make_tuple(nx,ny,numbering+1));
        }
    }
    if(water[N-1][N-1] == 0) {
        int aaaa = 0 ;
        for (int i = 0 ; i < N ; i++){
            for(int j =  0; j < N ; j++){
                if(board[i][j] == 0)
                    aaaa+=1;
            }
        }
        cout << aaaa -1<< '\n';
        return 0;
    }
    queue <tuple<int,int,int>> pq;
    pq.push(make_tuple(N-1,N-1,0));

    vector<vector<bool>> visited2(N, vector<bool>(N,false));
    while(!pq.empty()) {
        tie(x,y,numbering) =pq.front();
        pq.pop();
        if(visited2[y][x])
            continue;
        else {
            visited2[y][x] = true;
            person[y][x] = numbering;
        }
        for(int k = 0 ; k < 4 ; k++) {
            int nx = x + dx[k]; int ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                continue;
            if (person[ny][nx] == -1) {
                continue;
            }
            if (visited2[ny][nx])
                continue;
            pq.push(make_tuple(nx,ny,numbering+1));
        }
    }

    vector<pair<int,int>> candidates;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            if( (i == 0 && j == 0) || (i == N-1 && j == N-1) )
                continue;
            if(water[i][j] > person[i][j]) {
                candidates.push_back(make_pair(i,j));
            }
        }
    }

    for(int t = 0 ; t < candidates.size() ;t++) {
        vector<vector<int>> tBoard = board;
        tBoard[candidates[t].first][candidates[t].second] = -1;
        queue <pair<int,int>> tq;
        tq.push(make_pair(0,0));
        tBoard[0][0] = -1;
        while(!tq.empty()) {
            int lx = tq.front().first;
            int ly = tq.front().second;
            tq.pop();
            for (int k = 0 ; k < 4 ; k ++){
                int nx = lx + dx[k];
                int ny = ly + dy[k];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                    continue;
                if (tBoard[ny][nx] == -1) {
                    continue;
                }
                tBoard[ny][nx] = -1;
                tq.push(make_pair(nx,ny));
            }
        }
        int localAns = 0;
        for(int i = 0 ; i < N ; i++) {
            for (int j = 0 ; j < N ; j++) {
                if(tBoard[i][j] == 0)
                    localAns += 1;
            }
        }
        ans = bigger(ans,localAns);
    }
    cout << ans << '\n';
    return 0;
}