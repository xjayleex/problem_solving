#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cin >> N;
    int tmp;
    vector<vector<int>> board(N, vector<int>(N,0));
    vector<vector<int>> water(N, vector<int>(N,-1));
    vector<vector<int>> person(N, vector<int>(N,-1));

    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            cin >> tmp;
            if(tmp == 0)
                board[i][j] = 0;
            else
                board[i][j] = -1;
        }
    }
    queue <pair<int,int>> wq;
    wq.push(make_pair(0,0));
    water[0][0] = 0;
    while(!wq.empty()) {
        int x = wq.front().first;
        int y = wq.front().second;
        wq.pop();
        for(int k = 0 ; k < 4 ; k++) {
            int nx = x + dx[k]; int ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                continue;
            if (board[ny][nx] == -1)
                continue;
            if (water[ny][nx] != -1)
                continue;
            water[ny][nx] = water[y][x] + 1;
            wq.push(make_pair(ny,nx));
        }
    }
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            cout << water[i][j] << ' ';
        }
        cout << '\n';
    }
    queue <pair<int,int>> pq;
    pq.push(make_pair(N-1,N-1));
    while(!pq.empty()) {
        int x = pq.front().first;
        int y = pq.front().second;
        pq.pop();
        for(int k = 0 ; k < 4 ; k++) {
            int nx = x + dx[k]; int ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                continue;
            if (board[ny][nx] == -1)
                continue;
            if (person[ny][nx] != 0)
                continue;
            person[ny][nx] = person[y][x] + 1;
            pq.push(make_pair(ny,nx));
        }
    }
    vector<pair<int,int>> candidates;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            if( (i == 0 && j == 0) || (i == N-1 && j == N-1) )
                continue;
            if(water[i][j] > person[i][j]) {
                candidates.push_back(make_pair(j,i));
            }
        }
    }
    for(int i = 0 ; i < candidates.size() ;i++) {
        cout << candidates[i].first << ' ' << candidates[i].second << '\n';
    }

    return 0;
}