#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, mafia;
vector<vector<int>> dR;
int ans = 0;
bool f = false;
int bigger(const int &a, const int &b){ return a >  b ? a : b; };
struct Info {
    bool dead;
    int score;
};
int findTarget(const vector<Info> &infos){
    int maxId = 0; bool flag = false;
    for (int i = 0 ; i < infos.size(); i++) {
        if(!infos[i].dead) {
            if (!flag) {
                maxId = i, flag = true;
            } else {
                if (infos[maxId].score < infos[i].score )
                    maxId = i;
            }
        }
    }
    if(!flag)
        return -1;
    else
        return maxId;
}
void dfs(int dayCnt, int remain, vector<Info> infos){
    if ( f ) return;
    if(infos[mafia].dead || remain == 1) {
        ans = bigger(ans,dayCnt);
        if (remain == 1 && infos[mafia].dead)
            f = true;
        return;
    }
    /*
     * remain 1 일때 은진이가 남아있으면, 최대한 많은 밤을 보낸 것이므로, f 플래그를 통해
     * 가지치기를 해준다.
     */
    if (remain % 2 == 0) { // night
        for(int i = 0 ; i < N ; i++){
            if(i == mafia) continue;
            if(infos[i].dead) continue;
            infos[i].dead = true;
            for(int j = 0 ; j < N ; j++) {
                if(infos[j].dead) continue;
                infos[j].score += dR[i][j];
            }
            dfs(dayCnt+1, remain-1, infos);
            if (f) return;
            for(int j = 0 ; j < N ; j++) {
                if(infos[j].dead) continue;
                infos[j].score -= dR[i][j];
            }
            /*
             * 점수변화 백트래킹 필요 !!
             * */
            infos[i].dead = false;
        }
    } else { // daylight
        int target = findTarget(infos); // target can be -1;
        infos[target].dead = true;
        dfs(dayCnt, remain-1, infos);
        if (f)
            return;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cin >> N;
    vector<Info> infos(N);
    vector<bool> visited(N);

    dR.resize(N, vector<int>(N,0));
    for(int i = 0 ; i < N ; i++) {
        cin >> infos[i].score;
    }
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < N ; j++) {
            cin >> dR[i][j];
        }
    }
    cin >> mafia;
    dfs(0,N,infos);
    cout << ans << '\n';
    return 0;
}