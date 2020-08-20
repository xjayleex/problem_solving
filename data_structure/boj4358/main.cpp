#include <iostream>
#include <map>
using namespace std;
int main() {
    map<string,int> mp;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int totalCnt = 0;
    string in;
    while(!cin.eof()){
        getline(cin,in);
        if(in == "")
            break;
        mp[in] += 1;
        totalCnt += 1;
    }
    cout << fixed;
    cout.precision(4);
    map<string,int>::iterator iter;
    for(iter = mp.begin(); iter != mp.end() ; iter++ ){
        cout << (*iter).first << ' ' << (double)((*iter).second * 100) / totalCnt << '\n';
    }
    return 0;
}