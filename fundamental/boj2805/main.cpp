#include <iostream>
#include <vector>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
vector <int> trees;
long calc(int val){
    long sum = 0;
    for (int i = 0 ; i < trees.size();i++){
        if(trees[i] > val) {
            sum += trees[i] - val;
        }
    }
    return sum;
}
int main() {
    cin >> N >> M;
    trees.resize(N);
    for (int i = 0 ; i < N; i++){
        cin >> trees[i];
    }
    sort(trees.begin(),trees.end());
    int left = 0;
    int right = trees[N-1];
    int mid;
    long sum = 0;
    int result = 0;
    while(left <= right) {
        mid = (left+right)/2;
        sum = calc(mid);
        if (sum == M){
            result = mid;
            break;
        } else if (sum < M){
            right = mid - 1;
        } else {
            result = mid;
            left = mid +1;
        }

    }
    cout << result << '\n';
    return 0;
}