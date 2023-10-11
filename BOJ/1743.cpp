#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int vis[101][101];
int board[101][101];
int N, M, K, x, y, max_cnt=0;
void BFS() {
    queue<pair<int, int>> Q;
    for ( int i = 1; i <= N; i++ ) {
        for ( int j = 1; j <= M; j++ ) {
            if ( board[i][j] && !vis[i][j]) {
                int cnt = 1;
                vis[i][j] = 1;
                Q.push({i, j});
                while (!Q.empty()) {
                    pair<int, int> cur = Q.front(); Q.pop();

                    for ( int dir = 0; dir < 4; dir++ ) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if ( !board[nx][ny] || vis[nx][ny] ) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                        cnt++;
                    }
                }
                if ( max_cnt < cnt ) 
                    max_cnt = cnt;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for ( int i = 0 ; i < K; i++ ) {
        cin >> x >> y;
        board[x][y] = 1;
    }

    BFS();
    cout << max_cnt;
}   