#include <iostream>
#include <string>
#include <vector>
using namespace std;
int s = 0, f = 0 , r = 0;
vector <int> queue;
void push(int x){
    queue.push_back(x);
    r++, s++;
}
int qSize(){
    return s;
}
bool empty() {
    return s > 0 ? false : true;
}
int pop(){
    if(!empty()) {
        s -= 1;
        return queue[f++];
    } else {
        return -1;
    }
}
void front() {
    if(qSize== 0){
        cout << "-1" << '\n';
    } else {
        cout << queue[f] << '\n';
    }
}
void back() {
    if(qSize == 0){
        cout << "-1" << '\n';
    } else {
        cout << queue[r-1] << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    string tmp;
    string numStr;
    int num;
    N++;
    while(N--) {
        std::getline(std::cin, tmp);
        if(tmp.substr(0,2) == "pu"){
            numStr = tmp.substr(5);
            num = stoi(numStr);
            push(num);
        } else if (tmp.substr(0,2) == "fr") {
            front();
        } else if (tmp.substr(0,2) == "si") {
            cout << qSize() << '\n';
        } else if (tmp.substr(0,2) == "em") {
            cout << empty() << '\n';
        } else if (tmp.substr(0,2) == "po") {
            cout << pop() << '\n';
        } else {
            back();
        }
    }
    return 0;
}