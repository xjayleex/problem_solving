#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool binarySearch(const int &e, const vector<int> &A, int left, int right){
    if(left > right) {
        return false;
    }
    int mid = (left + right ) / 2;
    if (e == A[mid]) {
      return true;
    } else if ( e > A[mid]) {
        return binarySearch(e, A, mid + 1, right);
    } else {
        return binarySearch(e, A, left, mid - 1);
    }
}
int main() {
    int N ;
    cin >> N;
    vector <int> A(N);
    for (int i = 0 ; i < N ; i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    int M ;
    cin >> M;
    vector <int> elems(M);
    for (int i = 0 ; i < M ; i++){
        cin >> elems[i];
    }
    for (int e : elems) {
        if(binarySearch(e, A, 0, A.size() - 1)) {
            cout << "1" << '\n';
        } else {
            cout << "0" << '\n';
        }
    }
    return 0;
}