#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
string board[51];
int R, C;
int vis[51][51];
int BFS() {
    queue<pair<int, int>> Q;

    for ( int i = 0; i < R; i++ )
        for ( int j = 0; j < C; j++ ) {
            if ( board[i][j] == '*' ) {
                vis[i][j] = -1;
                Q.push({i, j});
            }
        }

    for ( int i = 0; i < R; i++ )
        for ( int j = 0; j < C; j++ ) {
            if ( board[i][j] == 'S' ) {
                vis[i][j] = 1; // 고슴도치 시작 위치
                Q.push({i, j});
            }
        }

    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        
        if ( board[cur.X][cur.Y] == 'D' )
            return vis[cur.X][cur.Y]-1;

        for ( int dir = 0; dir < 4; dir++ ) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if ( nx < 0 || nx >= R || ny < 0 || ny >= C ) continue;

            if ( vis[cur.X][cur.Y] > 0 && ( board[nx][ny] == '.' || board[nx][ny] == 'D' ) && vis[nx][ny] == 0 ) {
                vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }

            if ( vis[cur.X][cur.Y] == -1 && board[nx][ny] == '.' && vis[nx][ny] == 0 ) {
                vis[nx][ny] = -1;
                Q.push({nx, ny});
            }
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    for ( int i = 0; i < R; i++ ) 
        cin >> board[i];
    
    int result = BFS();
    if ( result == -1 )
        cout << "KAKTUS\n";
    else
        cout << result << "\n";
}