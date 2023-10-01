#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
int board[51][51];
int vis[51][51];
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int w, h, cnt;
int BFS() {
    cnt = 0;
    queue<pair<int, int>> Q;

    for ( int i = 0; i < h; i++ )
        for ( int j = 0; j < w; j++ ) {
            cin >> board[i][j];
            vis[i][j] = 0;
        }

    for ( int i = 0; i < h; i++ ) {
        for ( int j = 0; j < w; j++ ) {
            if ( board[i][j] == 0 || vis[i][j] ) continue; 

            Q.push({i, j});
            vis[i][j] = 1;
            cnt++;

            while(!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();

                for ( int dir = 0; dir < 8; dir++ ) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if ( nx < 0 || nx >= h || ny < 0 || ny >= w ) continue;
                    if ( board[nx][ny] == 0 || vis[nx][ny] ) continue;

                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> w >> h;
        if ( w == 0 && h == 0 ) break;
        cout << BFS() << "\n";
    }
}