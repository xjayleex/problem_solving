#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string in;
    string quit = "QUIT";
    string end = "END";

    vector<vector<string>> cmds;
    bool flag = true;
    vector<string> tmp;
    while(true){
        cin >> in;
        if(in.compare(quit) == 0) {
            cout << "QQQQ";
        } else if (in.compare(end) == 0) {
            cout << "EEEEE";
        } else if (in.compare() == 0) {
            cout << "HHHHH";
        } else {

        }
    }
    return 0;
}