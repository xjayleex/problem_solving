#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>
using namespace std;
bool compare(const string &a, const string &b){
    if(a.length() == b.length()){
        return a < b;
    } else {
        return a.length() > b.length();
    }
}
int toNumber(char ch) {
    return ch - 'A';
}
struct Trie {
    bool isTerminal; bool isHit;
    Trie* child[26];
    Trie() : isTerminal(false), isHit(false) {
        memset(child,0,sizeof(child));
    }
    ~Trie(){
        for(int i = 0 ; i < 26 ; i++) {
            if(child[i]) delete child[i];
        }
    }

    void insert(const char *key){
        if(*key =='\0'){
            isTerminal = true;
        }else {
            int next = toNumber(*key);
            if (child[next] == NULL){
                child[next] = new Trie();
            }
            child[next]->insert(key+1);
        }
    }
    Trie *find(const char *key){
        if(*key == '\0')
            return this;
        int next = toNumber(*key);
        if(child[next] == NULL)
            return NULL;
        return child[next]->find(key+1);
    }

};

int dx [8] = {0,1,1,1,0,-1,-1,-1};
int dy [8] = {-1,-1,0,1,1,1,0,-1};
int scoring[9] = {0,0,0,1,1,2,3,5,11};
Trie *trie;
//vector <bool> isHit;
vector <string> ansList;
void dfs(int x, int y, string made, int len, vector<vector<bool>> &visited, const vector<string> &board) {
    Trie *tp = trie->find(made.c_str()); // trie에서 현재까지 만들어진 문자열을 찾아.
    if(tp == NULL) { // 그게 NULL 이면 더 볼 필요 없으니까 리턴
        return;
    } else { // 존재한다면,
        if(tp->isTerminal) { // 종료점인지 검사해보자.
            // Hit, and no return needed.
            // map에 단어 추가.
            if(!tp->isHit){
                ansList.push_back(made);
                tp->isHit = true;
            }
        }
    }
    if(len >= 8)
        return;
    for(int k = 0 ; k < 8 ; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
            continue;
        if(visited[ny][nx])
            continue;
        visited[ny][nx] = true;
        dfs(nx,ny,made+board[ny][nx],len+1,visited,board);
        visited[ny][nx] = false;
    }
}
int main() {


    int W,B; string in;
    scanf("%d",&W);
    vector <string> words(W);

    trie = new Trie();
    for(int i = 0 ; i < W ; i++) {
        cin >> in;
        trie->insert(in.c_str());
        words[i] = in;
    }

    cin >> B;
    for(int k = 0 ; k < B ; k++){
        /*cout << "-----------pre-test------------" <<'\n';
        for(int j = 0 ; j < words.size();j++){
            if(trie->find(words[j].c_str())->isHit) {
                cout << words[j] << " Hit : On" <<'\n';
            } else {
                cout << words[j] << " Hit : Off" <<'\n';
            }
        }
        cout << "-------------------------------" <<'\n';*/
        vector<string> board;
        vector<vector<bool>> visited(4,vector<bool>(4,false));
        for(int j = 0 ; j < 4 ;j++){
            cin >> in;
            board.push_back(in);
        }

        for(int y = 0 ; y < 4; y++){
            for(int x = 0; x < 4 ; x++) {
                visited[y][x] = true;
                dfs(x,y,string(1,board[y][x]),1,visited,board);
                visited[y][x] = false;
            }
        }
        sort(ansList.begin(),ansList.end(),compare);
        int score = 0;
        for (int j = 0 ; j < ansList.size();j++){
            score += scoring[ ansList[j].length() ];
        }
        cout << score << ' ' << ansList[0] << ' ' << ansList.size() << '\n';
        for (int j = 0 ; j < ansList.size();j++) {
            trie->find(ansList[j].c_str())->isHit = false;
        }

        ansList.clear();
    }
    return 0;
}