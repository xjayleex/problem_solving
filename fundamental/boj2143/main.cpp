#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getLower(vector<int> &v, const int &t){
    int left = 0, right = v.back();
    int mid;
    while(left < right){
        mid = (left + right) / 2;
        if(v[mid] < t) {
            left = mid + 1;
        } else
            right = mid;
    }
    return right;
}
int getHigher(vector<int> &v, const int &t){
    int left = 0, right = v.back();
    int mid;
    while(left < right){
        mid = (left + right) / 2;
        if(v[mid] <= t) {
            left = mid + 1;
        } else
            right = mid;
    }
    return right;
}
int main() {
    int T, ASize, BSize, tmp;
    vector <int> A,B;
    cin >> T;
    cin >> ASize;
    for(int i = 0 ; i < ASize ; i++) {
        cin >> tmp;
        A.push_back(tmp);
    }
    cin >> BSize;
    for(int i = 0 ; i < BSize ; i++) {
        cin >> tmp;
        B.push_back(tmp);
    }
    vector <int> aSub, bSub;
    for (int i = 0 ; i < ASize ; i++){
        int sum = A[i];
        aSub.push_back(A[i]);
        for (int j = i + 1 ; j < ASize ; j++) {
            sum += A[j];
            aSub.push_back(sum);
        }
    }

    for (int i = 0 ; i < BSize ; i++){
        int sum = B[i];
        bSub.push_back(B[i]);
        for (int j = i + 1 ; j < BSize ; j++) {
            sum += B[j];
            bSub.push_back(sum);
        }
    }
    sort(bSub.begin(),bSub.end());
    long long ans = 0;
    for (int e : aSub) {
        int diff = T - e;
        long long  lb = getLower(bSub, diff);
        long long  ub = getHigher(bSub, diff);
        ans += (ub-lb);
    }
    cout << ans;
    return 0;
}