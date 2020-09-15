#include <iostream>
#include <vector>
#include <deque>
using namespace std;
struct Data {
    int index;
    int value;
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 실행속도 향상
    int N, L;
    cin >> N >> L;
    vector<Data> arr(N);
    deque<Data> deq;
    for (int i = 0 ; i < N ; i++){
        cin >> arr[i].value;
        arr[i].index = i;
    }
    for (int i = 0 ; i < N ; i++) {
        if (!deq.empty() && deq.front().index <= i - L)
            deq.pop_front();
        // arr[i].value가 항상 가장 큰 수가 되도록...
        // 덱에서 ar[i]보다 큰 것들은 다 빼버린다.
        while(!deq.empty() && deq.back().value > arr[i].value)
            deq.pop_back();
        deq.push_back(arr[i]);
        cout << deq.front().value << ' ';
    }
    return 0;
}


/*
 *  시간초과 코드
Data getMinData(vector<Data> &arr, int to, const int &L) {
    Data min = arr[to - L + 1];
    for (int i = to - L + 2 ; i <= to ; i++) {
        if(min.value >= arr[i].value) {
            min.value = arr[i].value;
            min.index = arr[i].index;
        }
    }
    return min;
}
int main() {
    int N, L;
    cin >> N >> L;
    vector<Data> arr(N);
    vector<Data> result;
    for (int i = 0 ; i < N ; i++){
        cin >> arr[i].value;
        arr[i].index = i;
    }
    Data old = arr[0] ; Data *end;

    result.push_back(arr[0]);
    for (int i = 1 ; i < N ; i++) {
        end = &arr[i];
        if( old.index > end->index - L ) {
            if (old.value >= end->value) {
                old.index = end->index;
                old.value = end->value;
            }
        } else {
            old = getMinData(arr, end->index,L);
        }
        result.push_back(old);
    }
    for (int i = 0 ; i < result.size() ;i++){
        cout << result[i].value << ' ';
    }


    return 0;
}
*/