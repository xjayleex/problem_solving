#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    //int sqrtN = (int)sqrt(N) + 1;
    int sqrtN = N;
    int primeCnt = 0;
    vector <bool> booleanPrime(N+1,true);
    vector <int> primes;
    booleanPrime[0] = false, booleanPrime[1] = false;
    for(int i = 2 ; i <= sqrtN ; i++) {
        if(!booleanPrime[i])
            continue;
        primes.push_back(i);
        for(int j = i + i ; j <=sqrtN ; j += i ) {
            booleanPrime[j] = false;
        }
    }
    int s = 0 , e = 0;
    int sum = 0, cnt = 0;

    while(true){
        if (sum >= N ) {
            sum -= primes[s++];
        } else if( e >= primes.size()) {
            break;
        } else if(sum < N){
            sum += primes[e++];
        }

        if( sum == N ){
            cnt += 1;
        }
    }
    cout << cnt << '\n';
    return 0;
}