#include <iostream>
#include <vector>
#include <string>
using namespace std;
char preset[5] = {'a','n','t','i','c'};
bool visited[26] = {false};
int bigger(const int &a, const int &b) {
    return a > b ? a : b;
}
int ans = 0;
void dfs (int idx, int cnt, const int max, const vector<string> &words) {
    if ( cnt == max ) {
        //check stub
        int localAns = 0;
        for (int i = 0 ; i < words.size() ; i++) {
            bool flag = true;
            for(int j = 0 ; j < words[i].length() ; j++) {
                if (!visited[words[i][j] - 'a']){
                    flag = false;
                    break;
                }
            }
            if (flag)
                localAns += 1;
        }
        ans = bigger(ans,localAns);
        return;
    }
    for (int i = idx ; i < 26 ; i++) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(i, cnt + 1, max, words);
            visited[i] = false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0 ; i < 5 ; i++) {
        visited[preset[i]-'a'] = true;
    }
    int N,K;
    cin >> N >> K;
    if (K < 5) {
        cout << 0 << '\n';
        return 0;
    }
    else if (K == 26)
    {
        cout << N << '\n';
        return 0;
    }
    K = K-5;
    vector <string> words(N);
    for (int i = 0 ; i < N ; i++) {
        string tmp;
        cin >> tmp;
        tmp = tmp.substr(4,tmp.length());
        for (int j = 0 ; j < 4 ; j++) {
            tmp.pop_back();
        }
        words[i] = tmp;
    }

    dfs(0,0, K, words);
    cout << ans << '\n';
    return 0;
}