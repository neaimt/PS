#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
#define X first
#define Y second
int K, V, E, u, v;
int vis[20001];
vector<int> arr[20001];
void Initarr() {
    for ( int i = 1; i <= V; i++ ) {
        int size = arr[i].size();
        for ( int j = 0; j < size; j++ )
            arr[i].pop_back();
    }
    memset(vis, 0, sizeof(vis)); // vis 초기화
}
bool BFS() {
    queue<pair<int, int>> Q;
    for ( int i = 1; i <= V; i++ ) {
        if ( arr[i].size() == 0 || vis[i] != 0 ) continue;
        vis[i] = 1;
        Q.push({i, 1});

        while(!Q.empty()) {
            int nx = Q.front().X;
            int color = Q.front().Y;
            Q.pop();
            
            for ( int dir = 0; dir < arr[nx].size(); dir++ ) {
                if ( vis[arr[nx][dir]] == 0 ) { // 방문표시가 없음
                    vis[arr[nx][dir]] = (-1)*color;
                    Q.push({arr[nx][dir], (-1)*color});
                }
                else { // 방문표시가 있으면
                    if ( vis[nx] == vis[arr[nx][dir]] ) // 인접한 칸과 색깔이 같다면
                        return false;
                }
            }
        }
    }
    return true;
    
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K;
    for ( int i = 0; i < K; i++ ) {
        cin >> V >> E;
        for ( int j = 0; j < E; j++ ) {
            cin >> u >> v;
            arr[u].push_back(v);
            arr[v].push_back(u);
        }

        bool result = BFS();
        if ( result ) cout << "YES\n";
        else cout << "NO\n";

        Initarr();
    }

}