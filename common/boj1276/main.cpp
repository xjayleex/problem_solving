#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Bridge {
    int height;
    int from,to;
};
bool compare(const Bridge &a, const Bridge &b) {
    return a.height > b.height;
}
int main() {
    int N ; int a, b ,c; cin >> N;
    vector <Bridge> bridges(N);
    for (int i = 0 ; i < N ; i++) {
        cin >> bridges[i].height >> b >> bridges[i].to;
        bridges[i].from = b + 1;
    }
    bridges.push_back(Bridge{0,0,10001});
    sort(bridges.begin(),bridges.end(), compare);
    int sum = 0;
    for (int i = 0 ; i < bridges.size() - 1 ;i++) {
        int left, right; bool lflag = false, rflag = false;
        for (int j = i+1 ; j < bridges.size(); j++) {
            if ( !lflag && bridges[j].from <= bridges[i].from && bridges[i].from <= bridges[j].to){
                left = bridges[i].height - bridges[j].height;
                lflag = true;
            }
            if (!rflag &&  bridges[j].from <= bridges[i].to && bridges[i].to <= bridges[j].to) {
                right = bridges[i].height - bridges[j].height;
                rflag = true;
            }
        }
        sum += (left + right);
    }
    cout << sum << '\n';
    return 0;
}