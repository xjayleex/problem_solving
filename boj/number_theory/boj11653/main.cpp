#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
//에라토스테네스의 체를 이용해 N까지의 소수를 모두 걸러낸다. 그리고 나눠서 떨어지는 경우에만 나눈 소수를 출력하고 N은 몫으로 감소시키는 과정을 반복한다. -> 시간초과
//소수를 신경쓰지 않고 iterator를 2부터 sqrt(N) 까지 증가시키며 나누어 떨어지는 경우에 출력하고 N은 몫으로 감소시킨다 -> 맞았습니다!
int main() {
    int N;
    cin >> N;
    for (int i = 2 ; i <= sqrt(N) ; i++ ) {
        while(N%i == 0) {
            cout << i << '\n';
            N /= i;
        }
    }
    if (N!=1)
        cout << N << '\n';
    return 0;
}