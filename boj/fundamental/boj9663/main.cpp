#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int ans = 0;
int N;
bool possible(int row, const vector<vector<bool>> &board) {
    bool flag = true;
    for(int col = 0; col < N ; col++){
        if ( board[row][col] ) {
            flag = false;
            break;
        }
    }
    return flag;
}
void dfs(int row, const int &N, vector<vector<bool>> board) {
    if(row == N)
        return;
    if(possible(row, board)){

    }
    for (int r = row ; r < N ; r++){

    }
}
int main() {
    cin >> N;
    vector<vector<bool>> board(N, vector<bool>(N,false));
    dfs(0,N,board);
    cout << ans;
    return 0;
}