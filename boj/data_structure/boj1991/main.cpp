#include <iostream>
using namespace std;
int input[27][2];
void dfs_pre(int i){
    cout << char(i + 'A' - 1);
    if(input[i][0] != -18){
        dfs_pre(input[i][0]);
    }
    if(input[i][1] != -18){
        dfs_pre(input[i][1]);
    }
}
void dfs_in(int i){
    if(input[i][0] != -18){
        dfs_in(input[i][0]);
    }
    cout << char(i + 'A' - 1);
    if(input[i][1] != -18){
        dfs_in(input[i][1]);
    }
}
void dfs_post(int i){
    if(input[i][0] != -18){
        dfs_post(input[i][0]);
    }
    if(input[i][1] != -18){
        dfs_post(input[i][1]);
    }
    cout << char(i + 'A' - 1);
}
int main() {
    int N;
    char A , B, C;
    cin >> N;
    for (int i = 1 ; i < 27 ; i++){
        input[i][0] = 0;
        input[i][1] = 0;
    }
    for (int i = 0; i < N ; i++) {
        cin >> A >> B >> C;
        input[A - 'A' + 1][0] = B - 'A' + 1;
        input[A - 'A' + 1][1] = C - 'A' + 1;
    }
    dfs_pre(1);
    cout <<'\n';
    dfs_in(1);
    cout <<'\n';
    dfs_post(1);
    cout <<'\n';
    return 0;
}