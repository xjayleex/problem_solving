#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[4000];
int b[4000];
int c[4000];
int d[4000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long result = 0;
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    vector <int> bar(n*n);
    int idx = 0;
    for(int i = 0 ; i < n ; i++) {
        for (int j = 0; j < n ; j++){
            bar[idx++] = c[i] + d[j];
        }
    }
    sort(bar.begin(),bar.end());
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            int ab = a[i]+b[j];
            long long lb = lower_bound(bar.begin(),bar.end(),-ab) - bar.begin();
            long long hb = upper_bound(bar.begin(),bar.end(),-ab) - bar.begin();
            if(-ab == bar[lb])
                result += (hb-lb);
        }
    }
    cout << result << '\n';
    return 0;
}