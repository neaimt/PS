#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second
int N, M, s, e, x, y, cnt=0;
int vis[101];
vector<int> map[101];
int BFS() {
    queue<pair<int, int>> Q;
    Q.push({s, 0});
    vis[s] = 1;
    while (!Q.empty()) {
        int nx = Q.front().X;
        int cnt = Q.front().Y;
        Q.pop();

        if ( nx == e ) 
            return cnt;

        for ( int i = 0; i < map[nx].size(); i++ ) {
            if ( vis[map[nx][i]] == 1 ) continue;

            Q.push({map[nx][i], cnt+1});
            vis[nx] = 1;
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    cin >> s >> e;
    cin >> M;
    for ( int i = 0; i < M; i++ ) {
        cin >> x >> y;
        map[x].push_back(y);
        map[y].push_back(x);
    }
    cout << BFS();

}