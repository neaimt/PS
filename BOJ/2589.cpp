#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define X first
#define Y second
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int N, M, m=0;
string board[51];
int vis[51][51];
int BFS(int x, int y) {
    memset(vis, -1, sizeof(vis));

    queue<pair<int, int>> Q;
    int cnt = 0;
    vis[x][y] = 0;
    Q.push({x, y});

    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        
        for ( int dir = 0 ; dir < 4; dir++ ) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if ( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
            if ( board[nx][ny] == 'W' || vis[nx][ny] > -1 ) continue;

            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            cnt = vis[cur.X][cur.Y] + 1;

            Q.push({nx, ny});
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for ( int i = 0; i < N; i++ )
        cin >> board[i];

    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < M; j++ ) {
            if ( board[i][j] == 'L' ) {
                m = max(BFS(i, j), m);
            }
        }
    }

    
    cout << m;
}
