#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    queue <int> q[21];
    int N, K, nowLen;
    string str;
    cin >> N >> K;
    unsigned long long ans = 0;
    for (int i = 1 ; i <= N ; i++) {
        cin >> str;
        nowLen = str.length();
        while(!q[nowLen].empty()) {
            int top = q[nowLen].front();
            if(i - top > K) q[nowLen].pop();
            else break;
        }
        ans += q[nowLen].size();
        q[nowLen].push(i);
    }
    cout << ans << '\n';
    return 0;
}