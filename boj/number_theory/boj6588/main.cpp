#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int x, N = 1000000;
    int sqrtN = N;
    vector <int> in;
    while(true){
        scanf("%d",&x);
        if(x == 0)
            break;
        in.push_back(x);
    }
    vector<bool> bPrime(sqrtN+1,true);
    vector<int> primes;// 2 3 5 7 11 13 17 19 23...
    // primes[x] = a , if bPrime[N - primes[x]] = true;
    for (int i = 2 ; i <= sqrtN ; i++) {
        if(!bPrime[i])
            continue;

        for(int j = i + i ; j <= sqrtN ; j += i) {
            bPrime[j] = false;
        }
    }
    for(int i = 0 ; i < in.size(); i++){
        int even = in[i];
        int B = in[i]+1;
        int A;
        bool flag = false;
        while(B > even / 2) {
            B -= 2;
            if(!bPrime[B])
                continue;
            A = even - B;
            if (A == 1)
                continue;
            if(bPrime[A]) {
                flag = true;
                cout << even << " = " << A << " + " << B << '\n';
                break;
            }
        }
        if (flag) {
            continue;
        } else {
            cout <<  "Goldbach's conjecture is wrong." << '\n';
        }

    }
    return 0;
}