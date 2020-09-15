#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N, M, L;
    cin >> N >> M >> L;
    vector<int> oilbank;
    int t;
    oilbank.push_back(0);
    for (int i = 0 ; i < N ; i++) {
        cin >> t;
        oilbank.push_back(t);
    }
    oilbank.push_back(L);
    sort(oilbank.begin(),oilbank.end());
    int left = 1, right = L-1;
    while(left <= right) {
        int mid = (left + right)/2;
        int newCnt = 0;
        for (int i = 1 ; i < oilbank.size() ; i++) {
            int dist = oilbank[i] - oilbank[i-1];
            newCnt += dist / mid ;
            if( dist % mid == 0) {
                   newCnt -= 1;
            }
        }
        if( newCnt > M )
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << left << '\n';
    return 0;
}