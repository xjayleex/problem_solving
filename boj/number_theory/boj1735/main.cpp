#include <iostream>
using namespace std;
int gcd (int a, int b){
    int r;
    while(b!=0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main() {
    int a,b;
    int c,d;
    cin >> a >> b;
    cin >> c >> d;
    int gcdVal = gcd(a,b);
    a = a / gcdVal; b = b / gcdVal;
    gcdVal = gcd(c,d);
    c = c / gcdVal; d = d / gcdVal;
    int e,f;
    e = (b * c) + (a * d);
    f = b * d;
    gcdVal = gcd(e,f);
    e = e / gcdVal;
    f = f / gcdVal;
    cout << e << ' ' << f << '\n';
    return 0;
}