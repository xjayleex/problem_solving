#include <iostream>
#include <vector>
using namespace std;
int main() {
    int ans = 0;
    int N, M;
    int s = 0,e = 0;
    cin >> N >> M;
    vector <int> v;
    int t;
    for (int i = 0; i < N ; i ++) {
        cin >> t;
        v.push_back(t);
    }
    int sum = 0;
    while(true) {
        if(sum >= M)
            sum -= v[s++];
        else if (e == N)
            break;
        else
            sum += v[e++];
        if(sum == M)
            ans+=1;
    }
    cout << ans << '\n';
    return 0;
}