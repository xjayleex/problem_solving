#include <iostream>
using namespace std;
bool floyd[501][501]; // floyd[A][B] A가 B보다 작은 것이 확실할 때만 True.
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M, a, b;
    cin >> N >> M;
    for (int i = 0 ; i < M ; i++) {
        cin >> a >> b;
        floyd[a][b] = true;
    }
    for (int k = 1 ; k <= N ; k++) {
        for (int i = 1 ; i <= N ; i++) {
            for (int j = 1; j <= N ; j++) {
                // i가 k보다 작고, k가 j 보다 작으면 i도 j보다 작은것이 확실하므로
                if(floyd[i][k] && floyd[k][j] )
                    floyd[i][j] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 1 ; i <= N ; i++) {
        int cnt = 0;
        for (int j = 1 ; j <= N ; j++) {
            // 둘중에 하나라도 true이면 대소관계 확실한거임
            if(floyd[i][j] || floyd[j][i])
                cnt += 1;
        }
        // 대소관계 확실한 갯수가 N-1 이면
        if ( cnt == N-1 )
            ans += 1;
    }
    cout << ans << '\n';
    return 0;
}