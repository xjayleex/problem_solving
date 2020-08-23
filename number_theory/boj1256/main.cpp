#include <iostream>
using namespace std;
int combi[201][201];
void makeCombi(){
    for (int n = 1 ; n <= 200 ; n++) {
        for (int c = 1 ; c <= 200 ; c++){
            if( n == c ) {
                combi[n][c] = 1;
            } else if ( c == 1 ) {
                combi[n][c] = n;
            } else {
                combi[n][c] = combi[n-1][c-1] + combi[n-1][c];
                if (combi[n][c] > 1000000000)
                    combi[n][c] = 1000000000;
            }
        }
    }
}
string ans ="";
void query (int n, int m, int k){
    // n + m == 0
    if (n + m == 0) {
        return;
    } else if(n == 0){ // 선택할 수 있는 a가 없음 -> z로
        ans += 'z';
        query(n,m-1,k);
    } else if (m == 0) { // 선택할 수 있는 z가 없음 ->a로
        ans += 'a';
        query(n-1,m,k);
    } else { // a나 z중 선택
        int aCount = combi[n+m-1][m];
        if (aCount >= k ) {
            ans += 'a';
            query(n-1,m,k);
        } else {
            ans += 'z';
            query(n,m-1,k - aCount);
        }
    }
}
int main() {
    makeCombi();
    int a , b , k;
    cin >> a >> b >> k;
    // A와 B
    if (combi[a+b][a] < k){
        cout << "-1" << '\n';
        return 0;
    }
    query(a,b,k);
    cout << ans << '\n';
    /*
    while (a + b == 0){
        if (a > 0) {
            ans += 'a';
            if(combi[a+b-1][a] < k) {
                k -= combi[a+b-1][a];
            }
            a -= 1;
        } else if (b > 0){
            ans += 'z';
            b -= 1;
        } else if ()
    }*/

    return 0;
}