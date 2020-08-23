#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
struct Point {
    int x; int y;
};
struct Hole {
    Point srcPoint;
    Point dstPoint;
    int time;
};
const int INF = 987654321;

int W, H;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
set <int> wall;
vector<pair<int,int>> adj[901];
vector <int> dist(901,INF);
int main() {

    int a,b;
    int G, xx,yy;
    int E ,x1,y1,x2,y2,t;
    while(true) {
        wall.clear();
        for (int i = 0 ; i <= 900 ; i++) {
            dist[i] = INF;
            adj[i].clear();
        }
        cin >> a >> b;
        if (a == 0 && b == 0) {
            break;
        }
        W = a, H = b;
        cin >> G;
        for (int i = 0 ; i < G ; i++) {
            cin >> xx >> yy;
            wall.insert(yy*W+xx);
        }

        cin >> E;
        vector<Hole> holes(E);
        for (int i = 0 ; i < E ;i++) {
            cin >> x1 >> y1 >> x2 >> y2 >> t;
            holes[i] = Hole{Point{x1,y1},Point{x2,y2},t};
        }
        // Solve >>>


        for (int i = 0 ; i < holes.size() ; i++) {

            adj[holes[i].srcPoint.y * W + holes[i].srcPoint.x].push_back(
                    make_pair(holes[i].dstPoint.y * W + holes[i].dstPoint.x, holes[i].time)
            );
        }


        for (int y = 0 ; y < H ; y++) {
            for (int x = 0 ; x < W ; x++) {
                int src = y * W + x;
                if(wall.count(src))
                    continue;
                if(!adj[src].empty()) // 위에서 귀신구멍 요소들 넣어줬으니, empty하지 않다면 귀신구멍임
                    continue;
                if(src == W*H - 1) // 도착점이면,
                    continue;
                for (int k = 0 ; k < 4 ; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx < 0 || ny < 0 || nx >= W || ny >= H)
                        continue;
                    int dst = W * ny + nx;
                    if(wall.count(dst))
                        continue;
                    adj[src].push_back(make_pair(dst,1));
                }
            }
        }

        dist[0] = 0;
        bool updated = false;
        for(int k = 0; k < W*H ; k++) {
            updated = false;
            for(int here = 0; here < W*H; here++) {
                if(dist[here] == INF)
                    continue;
                for(auto &next : adj[here]) {
                    if(dist[next.first] > dist[here] + next.second) {
                        dist[next.first] = dist[here] + next.second;
                        updated = true;
                    }
                }
            }
            if(!updated)
                break;
        }

        if(updated)
            cout << "Never\n";
        else if(dist[W*H-1] == INF)
            cout << "Impossible\n";
        else
            cout << to_string(dist[W*H-1]) << '\n';
    }
    return 0;
}