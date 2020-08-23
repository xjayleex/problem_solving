#include <iostream>
using namespace std;
int gcdLtoR[1000001];
int gcdRtoL[1000001];
int in[1000001];
int maxGCD = 1;
int bigger(const int &a, const int &b){
    return a > b ? a : b;
}
int gcd(int a, int b) {
    int r;
    while(b != 0) {
        r = a % b;
        a = b;
        b = r;
    } return a;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    for(int i = 0 ; i < N ; i++){
        cin >> in[i];
    }
    gcdLtoR[0] = in[0];
    for(int i = 1; i < N ; i++){
        gcdLtoR[i] = gcd(gcdLtoR[i-1],in[i]);
    }
    gcdRtoL[N-1] = in[N-1];
    for(int i = N - 2 ; i >= 0 ; i--){
        gcdRtoL[i] = gcd(gcdRtoL[i+1],in[i]);
    }
    int index = -1;
    for(int i = 0 ; i < N ; i++) {
        int now;
        if(i == 0) {
            now = gcdRtoL[1];
        } else if (i == N-1) {
            now = gcdLtoR[N-2];
        } else {
            now = gcd(gcdLtoR[i-1],gcdRtoL[i+1]);
        }
        if(gcd(in[i],now) == now)
            continue;
        if(maxGCD < now ){
            maxGCD = now;
            index = i;
        }
    }
    if (index == -1){
        cout << "-1\n";
    } else{
        cout << maxGCD << ' ' << in[index] << '\n';
    }

    return 0;
}
