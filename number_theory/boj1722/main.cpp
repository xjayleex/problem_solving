#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll fact[21];
void makeFactorial(){
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2 ; i <= 20 ;i++){
        fact[i] = fact[i-1] * i;
    }
}
bool visited[21];
string ansA ="";
void SolveA(int N){
    ll target; cin >> target;

    for (int i = 0 ; i < N ; i++){
        for (int j = 1 ; j <= N ; j++){
            if(visited[j])
                continue;
            if(target > fact[N - i -1]){
                target -= fact[N-i-1];
            } else {
                cout << j << ' ';
                visited[j] = true;
                break;
            }
        }
    }
}
void SolveB(int N){
    vector<int> in(N);
    for (int i = 0 ; i < N ; i++){
        cin >> in[i];
    }
    // ex. 3 2 1 4;
    ll ansB = 0;
    for (int i = 0 ; i < in.size() ; i++){
        int curr = in[i];
        for (int j = 1 ; j < curr ; j++) {
            if (!visited[j]){
                ansB += fact[N-i-1];
            }
        }
        visited[ curr ] = true;
    }
    cout << ansB + 1 << '\n'; // 앞에서 더 해줬던 cnt들의 다음 것이 입력 수열이므로 + 1.

}
int main() {
    int N, A;
    cin >> N;
    cin >> A;
    makeFactorial();
    if ( A == 1) {
        SolveA(N);
    } else {
        SolveB(N);
    }
    return 0;
}