#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define X first
#define Y second
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int board[101][101];
int vis[101][101];
int N, M, cnt=0, prev_cnt=0, t=0;
int BFS() {
    memset(vis, 0, sizeof(vis));
    prev_cnt = cnt;
    queue<pair<int, int>> Q;
    for ( int i = 0; i < N; i++ )
        for ( int j = 0; j < M; j++ ) {
            if ( i == 0 || i == N-1  || j == 0 || j == M-1 ) {
                vis[i][j] = 1;
                Q.push({i, j});
            }
        }
    
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();

        for ( int dir = 0; dir < 4; dir++ ) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if ( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
            if ( !board[nx][ny] && !vis[nx][ny] ) {
                vis[nx][ny] = 1;
                Q.push({nx, ny});
            }
            if ( board[nx][ny] && !vis[nx][ny] ) {
                board[nx][ny] = 0;
                vis[nx][ny] = 1;
                cnt--;
            }
        }
    }
    return cnt;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for ( int i = 0; i < N; i++ )
        for ( int j = 0; j < M; j++ ) {
            cin >> board[i][j];
            if ( board[i][j] == 1 )
                cnt++;
        }
    
    cnt = BFS();
    t = 1;
    while ( cnt ) {
        t++;
        BFS();
    }
    cout << t << "\n" << prev_cnt;

}
