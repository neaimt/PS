#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define X first
#define Y second
int board[101];
int vis[101];
int N, M, u, v, x, y;
int BFS() {
    queue<pair<int, int>> Q;
    Q.push({1, 0});

    while(!Q.empty()) {
        int nx = Q.front().X;
        int cnt = Q.front().Y;
        Q.pop();
        
        if ( nx == 100 )
            return cnt;

        for ( int i = 6; i >= 1; i-- ) {
            if ( vis[nx+i] == 0 ) continue;
            if ( nx+i > 100 ) continue;

            if ( vis[nx+i] == 1 ) { // 사다리
                vis[nx+i] = 0;
                Q.push({board[nx+i], cnt+1});
            }
            else if ( vis[nx+i] == 2 ) { // 뱀
                vis[nx+i] = 0;
                Q.push({board[nx+i], cnt+1});
            }
            else {
                vis[nx+i] = 0;
                Q.push({nx+i, cnt+1});
            }
        } 
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    memset(vis, -1, sizeof(vis));
    for ( int i = 0; i < N; i++ ) { // 사다리 정보
        cin >> x >> y;
        board[x] = y;
        vis[x] = 1;
    }

    for ( int i = 0; i < M; i++ ) { // 뱀 정보
        cin >> u >> v;
        board[u] = v;
        vis[u] = 2;
    }

    cout << BFS();
}