#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long ans = 0;
    int N,K;
    int w,v;
    cin >> N >> K;
    vector<pair<int,int>> gems;
    vector<int> bag;
    priority_queue< int ,vector<int>,less<int>> pq;
    for (int i = 0 ; i < N ; i++){
        cin >> w >> v;
        gems.push_back(make_pair(w,v));
    }
    for (int i = 0 ; i < K ; i++){
        cin >> w;
        bag.push_back(w);
    }

    sort(bag.begin(),bag.end());
    sort(gems.begin(),gems.end());
    int bagSize;
    int j = 0;
    for(int i = 0 ; i < bag.size() ; i++ ) {
        bagSize = bag[i];
        while(j < gems.size() && gems[j].first <= bagSize){
            // 보석 무게(first)가 가방 사이즈보다 작으면,
            pq.push( gems[j++].second);
        }
        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';
    return 0;
}