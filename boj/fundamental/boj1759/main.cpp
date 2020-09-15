#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool visited [26] = {false};
bool isValid(const string &pwd){
    int moCnt = 0;
    for(int i = 0 ; i < pwd.length(); i++){
        if(pwd[i] == 'a' || pwd[i] == 'e' || pwd[i] == 'i' || pwd[i] == 'o' || pwd[i] == 'u') {
            moCnt += 1;
        }
    }
    if (moCnt >= 1 && pwd.length() - moCnt >=2) {
        return true;
    } else {
        return false;
    }
}
void dfs(int idx, int cnt, const int &Len, string pwd,const vector<char> &candidates) {
    if(cnt == Len) {
        if(isValid(pwd)) {
            cout << pwd << '\n';
        }
        return;
    }
    for (int i = idx ; i < candidates.size() ; i++) {
        if (!visited[candidates[i] - 'a']) {
            visited[candidates[i] - 'a'] = true;
            dfs(i, cnt + 1, Len, pwd + candidates[i], candidates);
            visited[candidates[i] - 'a'] = false;
        }
    }
}
int main() {
    int L,C;
    cin >> L >> C;
    vector <char> candidates (C);
    for (int i = 0 ; i < C ; i++) {
        cin >> candidates[i];
    }
    sort(candidates.begin(),candidates.end());
    string pwd;
    dfs(0,0,L, pwd, candidates);
    return 0;
}