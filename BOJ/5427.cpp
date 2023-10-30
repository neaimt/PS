#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define X first
#define Y second
string map[1001];
int vis[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int T, w, h, ex, ey, result=0;
int BFS() {
    queue<pair<int, int>> Q;

    for ( int i = 0; i < h; i++ )
        for ( int j = 0; j < w; j++ ) {
            if ( map[i][j] == '*' ) {
                vis[i][j] = -1;
                Q.push({i, j});
            }
        }

    for ( int i = 0; i < h; i++ )
        for ( int j = 0; j < w; j++ ) {
            if ( map[i][j] == '@') {
                vis[i][j] = 1;
                Q.push({i, j});
            }
        }

    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();

        for ( int dir = 0; dir < 4; dir++ ) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if ( vis[cur.X][cur.Y] <= 0 && (nx < 0 || nx >= h || ny < 0 || ny >= w )) continue;
            if ( vis[cur.X][cur.Y] > 0 && (nx < 0 || nx >= h || ny < 0 || ny >= w ))
                return vis[cur.X][cur.Y];
            
            if ( vis[nx][ny] || map[nx][ny] == '#') continue;

            if ( vis[cur.X][cur.Y] == -1  && map[nx][ny] == '.' ) { // 불 확장
                vis[nx][ny] = -1;
                Q.push({nx, ny});
            }

            else if ( vis[cur.X][cur.Y] > 0 && map[nx][ny] == '.' ) { // 상근이 이동
                vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
    }
    return -1;
}
int findExit() {
    for ( int i = 0; i < h; i++ )
        for ( int j = 0; j < w; j++ )
            if ( i == 0 || i == h-1 || j == 0 || j == w-1 ) {
                if ( vis[i][j] > 0 )
                    return vis[i][j];
            }

    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for ( int c = 0; c < T; c++ ) { 
        cin >> w >> h;
        for ( int i = 0; i < h; i++ ) 
            cin >> map[i];
        
        result = BFS();

        if ( result == -1 )
            cout << "IMPOSSIBLE" << '\n';
        else 
            cout << result << '\n';

        for ( int j = 0; j < h; j++ ) {
            for ( int k = 0; k < w; k++ ) {
                vis[j][k] = 0;
                map[j][k] = 0;
            }
        }
    }
}