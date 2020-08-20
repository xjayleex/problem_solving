#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
int mini = INT_MAX;
using namespace std;
int smaller(int a, int b) {
    return a < b ? a : b;
}
int main() {
    vector <int> test {
        1,2,3,4,4,5
    };

    int N,H;
    cin >> N >> H;
    vector <int> bot;
    vector <int> top;
    int tmp;
    for (int i = 0 ; i < N ; i++) {
        cin >> tmp;
        if ( i % 2 == 0) {
            bot.push_back(tmp);
        } else {
            top.push_back(tmp);
        }
    }
    sort(bot.begin(),bot.end());
    sort(top.begin(),top.end());
    int rangeCnt = 0;
    for (int h = 1; h <= H ; h++) {
        int cnt = 0;
        int lb = lower_bound(bot.begin(),bot.end(),h) - bot.begin();
        cnt += (bot.size() - lb);
        lb = lower_bound(top.begin(),top.end(), (H - h + 1) ) - top.begin();
        cnt += (top.size() - lb);
        if ( mini > cnt) {
            mini = cnt;
            rangeCnt = 1;
        } else if ( mini == cnt) {
            rangeCnt += 1;
        }
    }
    cout << mini << ' '  << rangeCnt << '\n';
    return 0;
}