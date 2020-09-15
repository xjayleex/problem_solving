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
    pair<int,int> S,F; // pair(X,Y)
    cin >> N >> M;
    vector <string> in; string tmp;
    vector <vector<int>> board(N, vector<int>(M,0));
    vector <vector<int>> dist(N, vector<int>(M,20000000));
    cout << N << M <<'\n';
    for (int i = 0 ; i < N ; i++) {
        cin >> tmp;
        in.push_back(tmp);
        /*for (int j = 0 ; j < tmp.length() ; j++) {
            if(tmp[j] == 'F'){
                F = make_pair(j,i);
            } else if (tmp[j] == 'S') {
                S = make_pair(j,i);
            } else if (tmp[j] == 'g') {
                board[i][j] = 2501;
            }
            cout << "check0" ;
        }*/
        cout << "check "<< i << ' ' << tmp;
    }
    cout << "check2" ;
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
    cout << "check1" ;
    priority_queue <tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    pq.push(make_tuple(0,S.first,S.second));
    while(!pq.empty()) {
        int cost, x, y;
        tie(cost,x,y) = pq.top(); pq.pop();
        if (in[y][x] == 'F')
            break;
        if( dist[y][x] < cost )
            continue;
        else {
            dist[y][x] = cost;
        }
        for(int k = 0 ; k < 4 ; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if ( nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            int nCost = dist[y][x] + board[ny][nx];
            pq.push(make_tuple(nCost,nx,ny));
        }
    }

    return 0;
}