#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector <int> stack;
int idx = 0;
void Push(int x) {
    if (idx >= stack.size()){
        stack.push_back(x);
        idx += 1;
    } else {
        stack[idx++] = x;
    }
}
bool empty(){
    if ( idx <= 0) {
        return true;
    } else {
        return false;
    }
}
void Empty() {
    cout << empty() << '\n';
}
int pop() {
    if(!empty()) {
        idx -= 1;
        return stack[idx];
    } else {
        return -1;
    }
}
void Pop() {
    cout << pop() << '\n';
}
void Size(){
    cout << idx << '\n';
}
void Top(){
    if(idx > 0) {
        cout << stack[idx-1] << '\n';
    } else {
        cout << -1 << '\n';
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
            Push(num);
        } else if (tmp.substr(0,2) == "to") {
            Top();
        } else if (tmp.substr(0,2) == "si") {
            Size();
        } else if (tmp.substr(0,2) == "em") {
            Empty();
        } else if (tmp.substr(0,2) == "po") {
            Pop();
        }
    }
    return 0;
}