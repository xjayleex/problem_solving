#include <iostream>
#include <vector>
using namespace std;
vector<int> players;
vector<int> temp;
vector<int> ranks;
///merge sort
struct Runner{
    long value;
    int position;
};
vector<Runner> runners;
vector<Runner> tempRunner;
void merge(int s, int m, int e){
    int p1 = s;
    int p2 = m + 1;
    int k = s;
    while(p1 <= m && p2 <= e){
        if (runners[p1].value <=runners[p2].value) {
            tempRunner[k++] = runners[p1++];
        } else {
            int cnt = p1 - s;
            ranks[runners[p2].position] -= cnt;
            tempRunner[k++] = runners[p2++];
        }
    }
    while(p1 <= m) {
        tempRunner[k++] = runners[p1++];
    }
    while(p2 <= e) {
        int cnt = p1 - s;
        ranks[runners[p2].position] -= cnt;
        tempRunner[k++] = runners[p2++];
    }
    for (int i = s ; i <= e ; i++){
        runners[i] = tempRunner[i];
    }
}
void mergeSort(int s, int e) {
    if ( s < e ) {
        int mid = (s + e) / 2;
        mergeSort(s, mid);
        mergeSort(mid+1, e);
        merge(s, mid, e);
    }
}

int main() {
    int N;
    cin >> N;
    int tmp;
    for (int i = 0 ; i < N ; i++){
        cin >> tmp;
        ranks.push_back(i+1);
        runners.push_back(Runner{tmp,i});
    }
    tempRunner.reserve(N);
    mergeSort(0,N-1);
    for(int i = 0 ; i < N ; i++) {
        cout << ranks[i] << '\n';
    }
    return 0;
}