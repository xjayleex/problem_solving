#include <iostream>
#include <stdlib.h>
using namespace std;
int board[9][9];
bool row[9][10];
bool col[9][10];
bool square[9][10];
void getInput(){
    for (int i = 0 ; i < 9 ; i++){
        for (int j = 0 ; j < 9 ; j++){
            cin >> board[i][j];
            if (board[i][j] != 0) {
                row[i][board[i][j]] = true;
                col[j][board[i][j]] = true;
                square[(i/3)*3+(j/3)][board[i][j]] = true;
            }
        }
    }
}
void dfs(int cnt){
    int y = cnt / 9;
    int x = cnt % 9;

    if (cnt == 81 ){
        for (int i = 0 ; i < 9 ; i++) {
            for (int j = 0 ; j < 9 ; j++){
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }
    if (board[y][x] == 0){
        for (int i = 1 ; i <= 9 ; i++){
            if(row[y][i] == false && col[x][i] == false && square[(y / 3) * 3 + (x / 3)][i] == false) {
                row[y][i] = true;
                col[x][i] = true;
                square[(y / 3) * 3 + (x / 3)][i] = true;
                board[y][x] = i;
                dfs(cnt+1);
                row[y][i] = false;
                col[x][i] = false;
                square[(y / 3) * 3 + (x / 3)][i] = false;
                board[y][x] = 0;

            }
        }
    } else {
        dfs(cnt+1);
    }
}

int main() {
    getInput();
    dfs(0);
    return 0;
}