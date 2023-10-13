#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int board[1001][1001];
int vis[1001][1001];
int x, y, N, M;
void BFS() {
    queue<pair<int, int>> Q;
    vis[x][y] = 0; // 목표지점 
    Q.push({x, y});
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();

        for ( int dir = 0; dir < 4; dir++ ) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if ( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
            if ( !board[nx][ny] || vis[nx][ny] > -1 ) continue;
            
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for ( int i = 0; i < N; i++ ) 
        for ( int j = 0; j < M; j++ ) {
            cin >> board[i][j];
            if ( board[i][j] == 1 )
                vis[i][j] = -1;
            else if ( board[i][j] == 0 )
                vis[i][j] = -2;
            if ( board[i][j] == 2 ) {
                x = i;
                y = j;
            }
        }
    
    BFS();

    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < M; j++ ) {
            if ( vis[i][j] == -2 )
                cout << 0 << " ";
            else
                cout << vis[i][j] << " ";
        }
        cout << "\n";
    }

}