#include <iostream>
#include <vector>
using namespace std;
bool map[100];
struct Student {
    int id;
    int recommandCnt;
    int time;
    bool flag;
};
bool compare(const Student &a, const Student &b) {
    if(a.flag == true && b.flag == true ) {
        if (a.recommandCnt == b.recommandCnt) {
            return a.time < b.time;
        } else
            return a.recommandCnt < b.recommandCnt;
    } else if (a.flag == false && b.flag == false ){
        if (a.recommandCnt == b.recommandCnt) {
            return a.time < b.time;
        } else
            return a.recommandCnt < b.recommandCnt;
    }     else if (a.flag == true && b.flag == false ) {
        return true;
    } else {
        return false;
    }
}
bool compare2(const Student &a, const Student &b) {
    return a.id < b.id;
}
int main() {


    // tuple  -> id , recommandCnt, time,
    vector <Student> st;

    int N,C,tmp;
    cin >> N;
    cin >> C;
    vector <int> recmd;
    int cnt = 0;
    for (int i = 0 ; i < C ; i++){
        cin >> tmp;
        recmd.push_back(tmp-1);
    }
    for (int i = 0 ; i < 100 ; i++){
        st.push_back(Student{i,100000,100000,false});
    }

    for (int i = 0 ; i < recmd.size() ;i++) {
        int currentID = recmd[i];

        //cout << "curr " << currentID << endl;
        if( cnt <= N) { // 사진틀 비었을 때,
            if (map[currentID]) {
                st[currentID].recommandCnt += 1;
            } else {
                map[currentID] = true;
                st[currentID].recommandCnt = 1;
                st[currentID].time = i;
                st[currentID].flag = true;
                cnt +=1;
            }
        } else {
            if(map[currentID]){
                st[currentID].recommandCnt += 1;
                cout << currentID <<" : " <<st[0].id+1 << ' ' << st[0].recommandCnt << ' ' << st[0].time << ' ' << st[0].flag << '\n';
            } else {
                sort(st.begin(), st.end(), compare);
                cout << currentID <<" : "<<st[0].id+1 << ' ' << st[0].recommandCnt << ' ' << st[0].time << ' ' << st[0].flag << '\n';
                int old = st[0].id;
                st[0].recommandCnt = 100000;
                st[0].time = 100000;
                st[0].flag = false;
                map[old] = false;

                sort(st.begin(),st.end(),compare2);

                st[currentID].recommandCnt = 1;
                st[currentID].time = i;
                st[currentID].flag = true;
                map[currentID] = true;
            }
        }
    }
    vector <int> result;
    for (int i = 0 ; i < 100 ; i++){
        if(map[ st[i].id ])
            result.push_back(st[i].id);
    }
    sort(result.begin(), result.end());
    for (int i = 0 ; i < N ;i++){
        cout << result[i] << ' ';
    }
    return 0;
}