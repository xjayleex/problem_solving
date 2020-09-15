#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct Trie {
    bool isTerminal;
    int depth;
    Trie() {
        isTerminal = false;
        depth = 0;
    }
    map <string, Trie> child;
    void insert(int depth, const vector <string> &keyStrings) {
        if(depth == keyStrings.size()) {
            isTerminal = true;
            return;
        } else {
            string next = keyStrings[depth];
            this->depth = depth;
            if(child.find(next) == child.end()) {
                child[next] = Trie{};
                child[next].isTerminal = false;
            }
            child[next].insert(depth+1,keyStrings);
        }
    }
};
void dfs(Trie &trie) {

    map <string,Trie>::iterator iter;
    for(iter = trie.child.begin() ; iter != trie.child.end(); iter++) {
        for(int i = 0 ; i < trie.depth * 2 ; i++ ) {
            cout << '-';
        }
        cout << (*iter).first << '\n';
        dfs((*iter).second);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N,M; string tmp;
    cin >> N;
    Trie trie;
    for (int i = 0 ; i < N ; i++) {
        cin >> M;
        vector<string> g(M);
        for (int j = 0 ; j < M ; j++) {
            cin >> g[j];
        }
        trie.insert(0,g);
    }
    dfs(trie);


    return 0;
}