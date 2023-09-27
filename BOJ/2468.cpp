#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int board[101][101];
int vis[101][101];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int N, cnt[101], h=0, ans=1;
void BFS() {
    queue<pair<int, int>> Q;
    int c = 0;

    for ( int i = 0; i < N; i++ ) // 초기화
        for ( int j = 0; j < N; j++ )
            vis[i][j] = 0;
        
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ )
            if ( board[i][j] > h && vis[i][j] == 0 ) {
                Q.push({i, j});
                vis[i][j] = 1;

                while(!Q.empty()) {
                    pair<int, int> cur = Q.front(); Q.pop();

                    for ( int dir = 0; dir < 4; dir++ ) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if ( nx < 0 || nx >= N || ny < 0 || ny >= N ) continue;
                        if ( board[nx][ny] <= h || vis[nx][ny] ) continue;

                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
                c++;
            }
    }
    cnt[h] = c;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for ( int i = 0; i < N; i++ )
        for ( int j = 0; j < N; j++ )
            cin >> board[i][j];

    for ( int i = 0; i < N; i++ )
        for ( int j = 0; j < N; j++ ) 
            h = max(board[i][j], h);

    for ( ; h >= 1; h-- ) {
        BFS();
        ans = max(ans, cnt[h]);
    }

    cout << ans;
}