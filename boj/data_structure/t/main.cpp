#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <string>
using namespace std;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int main() {
    int N, M;
    cin >> N >> M;
    pair<int,int> S, F;
    vector <string> in; string tmp;
    vector <vector<int>> board(N, vector<int>(M,0));
    vector <vector<int>> dist(N, vector<int>(M,20000000));
    for (int i = 0 ; i < N ; i++) {
        cin >> tmp;
        in.push_back(tmp);
        for (int j = 0 ; j < tmp.length() ; j++) {
            if(tmp[j] == 'F'){
                F = make_pair(j,i);
            } else if (tmp[j] == 'S') {
                S = make_pair(j,i);
            } else if (tmp[j] == 'g') {
                board[i][j] = 2501;
            }
        }
    }
    for (int y = 0 ; y < N ; y++ ) {
        for (int x = 0 ; x < M ; x++) {
            if(board[y][x] == 2501)
                continue;
            if(in[y][x] == 'F')
                continue;
            if(in[y][x] == 'S')
                continue;
            for(int k = 0; k < 4 ; k++) {
                int tx = x + dx[k];
                int ty = y + dy[k];
                if( tx < 0 || ty < 0 || ty >= N || tx >= M)
                    continue;
                if( in[ty][tx]  == 'g') {
                    board[y][x] = 1;
                    break;
                }
            }
        }
    }



    priority_queue <tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    pq.push(make_tuple(0,S.first,S.second));

    while(!pq.empty()) {
        int cost, x, y;
        tie(cost, x, y) = pq.top();
        pq.pop();
        /*if (in[y][x] == 'F') {
            dist[y][x] = cost;
            break;
        }*/
        if( !(x == S.first && y == S.second) && dist[y][x] <= cost )
            continue;
        else {
            dist[y][x] = cost;
        }
        for(int k = 0 ; k < 4 ; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if ( nx < 0 || ny < 0 || ny >= N || nx >= M)
                continue;
            int nCost = dist[y][x] + board[ny][nx];
            pq.push(make_tuple(nCost,nx,ny));
            //cout <<  "  " << nCost << "  ";
        }
        //cout <<  '\n';
    }
    cout << dist[F.second][F.first] / 2501 << ' ' << dist[F.second][F.first] % 2501 << '\n';
    return 0;
}