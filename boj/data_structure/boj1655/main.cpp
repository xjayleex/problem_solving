#include <iostream>
#include <queue>
using namespace std;
// maxHeap 크기를 minHeap 크기보다 같거나 하나 크게.
// maxHeap의 최대 값은 minHeap의 최소값보다 작게
int main() {
    priority_queue<int,vector<int>,less<int>> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int N ;
    cin >> N;
    int num;
    for (int i = 0 ; i < N ;i++){
        cin >> num;
        if(maxHeap.size() == minHeap.size()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        if(!maxHeap.empty() && !minHeap.empty()) {
            if(maxHeap.top() > minHeap.top()) {
                int tmp = minHeap.top(); minHeap.pop();
                minHeap.push(maxHeap.top()); maxHeap.pop();
                maxHeap.push(tmp);
            }
        }
        cout << maxHeap.top() << '\n';
    }

    return 0;
}