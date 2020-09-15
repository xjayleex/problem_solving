#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,in;
    priority_queue<int,vector<int>,less<int>> pq;
    cin >> N;
    for (int i = 0 ; i < N ; i++){
        cin >> in;
        if (in == 0) {
            if(!pq.empty()){
                cout << pq.top() << '\n';
                pq.pop();
            } else {
                cout << 0 << '\n';
            }
        } else {
            pq.push(in);
        }
    }
    return 0;
}