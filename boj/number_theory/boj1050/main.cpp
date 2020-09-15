#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool visited[10];
int a[10];
vector<int> in;
vector<vector<int>> ans;

void dfs(int digit_index, int M,int prev){
    if ( digit_index == M) {
        vector<int> temp;
        for (int i = 0 ; i < M ;i++){
            temp.push_back(a[i]);
        }
        ans.push_back(temp);

        return;
    }
    if(prev == -1){
        prev = 0;
    }
    for (int i = prev ; i < in.size() ; i++){
        if(visited[i])
            continue;
        visited[i] = true;
        a[digit_index]= in[i];
        dfs(digit_index+1, M, i+1);
        visited[i] = false;
    }
}
int main() {
    int N,M;
    cin >> N >> M;
    for (int i = 0 ; i < N ; i++){
        int tmp;
        cin >> tmp;
        in.push_back(tmp);
    }
    sort(in.begin(),in.end());
    dfs(0,M,-1);
    sort(ans.begin(), ans.end());
    ans.resize (
            unique(ans.begin(), ans.end()) - ans.begin()
            );
    for (int i = 0 ; i < ans.size();i++ ){
        for (int j = 0 ; j < ans[i].size();j++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}