#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define X first
#define Y second
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N, M, cnt=0, result=0, ck=0;
int board[301][301];
int vis[301][301];
int Icenum();
void BFS(int x, int y) {
    queue<pair<int, int>> Q;
    vis[x][y] = 1;
    Q.push({x, y});

    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        int water = 0;

        for ( int dir = 0; dir < 4; dir++ ) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if ( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
            if ( board[nx][ny] == 0 && board[cur.X][cur.Y] > 0 && !vis[nx][ny] )
                board[cur.X][cur.Y]--;

            if ( board[nx][ny] && !vis[nx][ny] ) {
                vis[nx][ny] = 1;
                Q.push({nx, ny});
            }
        } 
    }
    memset(vis, 0, sizeof(vis));
    if ( Icenum() > 1 )
        ck = 1; 
}
int Icenum() {
    queue<pair<int, int>> Q;
    cnt = 0;
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < M; j++ ) {
            if ( board[i][j] == 0 || vis[i][j] ) continue;
            cnt++;
            vis[i][j] = 1;
            Q.push({i, j});

            while(!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();

                for ( int dir = 0; dir < 4; dir++ ) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if ( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
                    if ( !board[nx][ny] || vis[nx][ny] ) continue;

                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for ( int i = 0; i < N; i++ )
        for ( int j = 0; j < M; j++ )
            cin >> board[i][j];
    
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < M; j++ ) {
            if ( board[i][j] ) {
                result++;
                memset(vis, 0, sizeof(vis));
                BFS(i, j);
                if ( ck == 1 ) {
                    cout << result;
                    break;
                }
            }
        }
        if ( ck == 1 )
            break;
    }

    if ( ck == 0 )
        cout << 0;
}