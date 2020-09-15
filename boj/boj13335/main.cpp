#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,w,L;
int solution(vector<int> &weights) {
    queue <pair<int,int>> bridgeQ;
    queue <int> readyQ;
    int weightSum = 0;
    int time = 0;
    for(int &e : weights)
        readyQ.push(e);
    while(!readyQ.empty() || !bridgeQ.empty()) {
        time += 1;
        if(!bridgeQ.empty()) {
            if(time == bridgeQ.front().second) {
                weightSum -= bridgeQ.front().first;
                bridgeQ.pop();
            }
        }
        int nowWeight;
        if(!readyQ.empty()) {
            nowWeight = readyQ.front();
            if(w < weightSum + nowWeight) continue;
            readyQ.pop();
            int outTime = time + L;
            weightSum += nowWeight;
            bridgeQ.push(make_pair(nowWeight, outTime));
        }
    }
    return  time;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> L >> w;
    vector<int> weights(n);
    for (int i = 0 ; i < n ; i++) {cin >> weights[i];}
    cout << solution(weights) << '\n';
    return 0;
}