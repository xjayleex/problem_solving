#include <iostream>
#include <vector>

using namespace std;

int main() {

    int age; cin >> age; int tmp;
    int max_beat = 220 - age;
    vector<int> heartbeats;
    vector<int> kinds(6);
    /*do {
        cin >> tmp;
        heartbeats.push_back(tmp);
    } while (getc(stdin) == ' ');*/
    while(cin >> tmp) {
        heartbeats.push_back(tmp);
    }
    for(int i = 0 ; i < heartbeats.size() ; i++) {
        tmp =(heartbeats[i] * 100) / max_beat;
        if(tmp < 60) {
            kinds[5] += 1;
        } else if ( tmp >= 60 && tmp < 68 ) {
            kinds[4] += 1;
        } else if ( tmp >= 68 && tmp < 75 ) {
            kinds[3] += 1;
        } else if ( tmp >= 75 && tmp < 80 ) {
            kinds[2] += 1;
        } else if ( tmp >= 80 && tmp < 90 ) {
            kinds[1] += 1;
        } else  {
            kinds[0] += 1;
        }
    }
    for (int i = 0 ; i < 6 ; i++) {
        cout << kinds[i] << ' ';
    } cout << '\n';
    return 0;
}