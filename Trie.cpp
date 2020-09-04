#include <iostream>

#include <memory.h>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
#define PREFIX 1
#define SUFFIX 0
int toNumber(char ch){
    return ch - 'a';
}
int matchCnt = 0;
struct Trie {
    bool isTerminal;
    int length;
    Trie* child[26];
    unordered_map <int,int> mp;
    Trie(int l) : isTerminal(false) {
        memset(child, 0, sizeof(child));
        length = l;
    }

    ~Trie() {
        for (int i = 0; i < 26; i++)
            if (child[i])
                delete child[i];
    }
    void insert(const char* key,int len) {
        if (*key == '\0') {
            isTerminal = true;
        }
        else {
            int curr = toNumber(*key);
            mp[len] += 1;
            if (child[curr] == NULL) {
                child[curr] = new Trie(length + 1);
            }
            child[curr]->insert(key + 1, len);

        }
    }
    Trie* find(const char* key) {
        if (*key == '\0')
            return this;
        int curr = toNumber(*key);
        if (child[curr] == NULL)
            return NULL;
        return child[curr]->find(key + 1);
    }

};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    Trie* trie = new Trie(0);
    Trie* trieReverse = new Trie(0);
    Trie* triePtr;
    int type = 0;

    for (int i = 0 ; i < words.size() ; i++){
        trie->insert(words[i].c_str(), words[i].length());
        reverse(words[i].begin(),words[i].end());
        trieReverse->insert(words[i].c_str(),words[i].length());
    }
    for (int i = 0 ; i < queries.size() ; i++){
        string regex ;
        int localAnswer = 0;

        if (queries[i][0] == '?') {
            type = SUFFIX;
        } else {
            type = PREFIX;
        }
        if (type == PREFIX) {
            int to = 0 ;
            for (string::iterator iter = queries[i].begin(); iter!= queries[i].end();++iter){
                if (*iter == '?') {
                    break;
                } else {
                    to += 1;
                }
            }
            regex = queries[i].substr(0,to);;
            triePtr = trie->find(regex.c_str());
            if (triePtr == NULL){
                localAnswer = 0;
            } else {
                if (triePtr->mp.count(queries[i].length())){
                    localAnswer = triePtr->mp[queries[i].length()];
                }else {
                    localAnswer = 0;
                }
            }
        } else {
            int from = 0;

            for (string::reverse_iterator riter = queries[i].rbegin(); riter!= queries[i].rend(); ++riter){
                if (*riter == '?') {
                    break;
                } else {
                    from += 1;
                }
            }
            regex = (queries[i].substr(queries[i].length()-from, queries[i].length()));

            reverse(regex.begin(),regex.end());
            triePtr = trieReverse->find(regex.c_str());
            if (triePtr == NULL){
                localAnswer = 0;
            } else {
                if (triePtr->mp.count(queries[i].length())){
                    localAnswer = triePtr->mp[queries[i].length()];
                }else {
                    localAnswer = 0;
                }
            }

        }
        answer.push_back(localAnswer);
    }
    return answer;
}
