#include <iostream>
#include <vector>

using namespace std;
int smaller( const int &a, const int &b){
    return a < b ? a : b;
}
int main() {
    int N, M;
    vector <int> a;
    int s = 0, e = 0, sum =0, t = 0,min;
    cin >> N >> M;
    min = 987654321;
    for (int i = 0; i < N ; i++){
        cin >> t;
        a.push_back(t);
    }
    while(true){
        if ( sum >= M) {
            t = e - s ;
            cout << "e : " << e << " s : " << s << " t : " << t<< '\n';
            min = smaller(min,t);
            sum -= a[s++];
        } else if ( e == N) {
            break;
        } else if ( sum < M) {
            sum += a[e++];
        }
    }
    if ( min == 987654321) {
        cout << 0 << '\n';
    } else {
        cout << min << '\n';
    }

    return 0;
}