#include <iostream>
using namespace std;

int main() {
   long long X,Y;
   long long ans;
    cin >> X >> Y;
    int z  =  (Y * 100)  /  X ;
    if (z>=99){
        cout << -1 << '\n';
        return 0;
    }
    long long left = 0;
    long long right = 1000000000;
    while(left <= right) {
        long long mid = (left + right)/2;
        int new_z = ((Y + mid) * 100) / (X + mid);

        if(new_z > z) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}