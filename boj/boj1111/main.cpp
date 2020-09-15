#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N; vector <int> arr(N); for(int i = 0 ; i < N ; i++)  cin >> arr[i];
    if ( N == 1) {
        cout << "A" << '\n';
    } else if (N ==2) {
        if(arr[0] == arr[1])
            cout << arr[0] << '\n';
        else
            cout << "A" << '\n';
    } else {
        int a = 0;
        int x = arr[1] - arr[0];
        int y = arr[2] - arr[1];
        if (x != 0)
            a = y / x;
        bool flag = true;
        int b = arr[1] - a * arr[0];
        for ( int i = 1 ; i < N ; i++) {
            if ( arr[i] != arr[i-1] * a + b) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << arr[N-1] * a + b << '\n';
        } else
            cout << "B" << '\n';
    }
    return 0;
}