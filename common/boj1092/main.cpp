#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const int &a, const int &b) {
    return a > b;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int crainN, boxN;
    cin >> crainN;
    vector <int> crains (crainN);
    for (int i = 0 ; i < crainN ; i++) {
        cin >> crains[i];
    }
    cin >> boxN;
    vector <int> boxes(boxN);
    for (int i = 0 ; i < boxN ; i++) {
        cin >> boxes[i];
    }
    sort(boxes.begin(),boxes.end(), compare);
    sort(crains.begin(),crains.end(), compare);
    if(crains[0] < boxes[0]) {
        cout << "-1" << '\n'; return 0;
    }
    int cIndex = 0; int time = 0;
    while(!boxes.empty()) {
        cIndex = 0;
        for (int i = 0 ; i < boxes.size(); i++) {
            if(cIndex == crains.size()) break;
            if(crains[cIndex] >= boxes[i]) {
                cIndex += 1;
                boxes.erase(boxes.begin() + i);
                i -=1;
            } else {

            }
        }
        time += 1;
    }
    cout << time << '\n';
    return 0;
}