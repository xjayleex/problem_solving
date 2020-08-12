#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int K, N;
    cin >> K >> N;
    priority_queue<long long,vector<long long>,greater<long long>> pq;
    vector<long long> primes(K);
    int t;
    for(int i = 0 ; i < K ; i++){
        cin >> t;
        primes[i] = t;
        pq.push(t);
    }
    long long front = 0;
    for (int i = 0 ; i < N ; i++) {
        front = pq.top(); pq.pop();
        for (int j = 0 ; j < K ; j++){
            long long v = primes[j] * front;
            pq.push(v);
            if(front % primes[j] == 0) { // 기존 큐에서 곱해져서 나온 것이라면
                break;
            }
        }
    }
    cout << front << '\n';
    return 0;
}