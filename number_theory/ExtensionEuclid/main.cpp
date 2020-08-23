#include <iostream>
using namespace std;
int gcd(int a, int b) {
    while ( b!=0) {
        int r = a % b;
        a = b ;
        b = r ;
    }
    return a;
}
struct ExtGCDResult {
    long s,t,r;
    ExtGCDResult* eGCD(long a, long b) {
        long s0 = 1, t0 = 0, r0 = a;
        long s1 = 0, t1 = 1, r1 = b;
        long temp;
        while(r1 != 0) {
            long q = r0 /r1;
            temp = r0 - r1 * q; r0 = r1; r1 = temp;
        }
        return &ExtGCDResult{};
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}