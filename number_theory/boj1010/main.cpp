#include <iostream>
using namespace std;
int combi[31][31];
void makeCombi(){
    for (int n = 1; n <= 30; n++){
        for (int c = 1; c <= 30; c++){
            if(n == c) {
                combi[n][c] = 1;
            } else if ( c == 1) {
                combi[n][c] = n;
            } else {
                combi[n][c] = combi[n-1][c] + combi[n-1][c-1];
            }
        }
    }
}
int main() {
    makeCombi();
    int T,N,C;
    cin >> T;
    for(int i= 0; i < T ; i++){
        cin >> C >> N;
        cout << combi[N][C] << '\n';
    }
    return 0;
}