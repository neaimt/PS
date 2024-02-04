#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#define X first
#define Y second
using namespace std;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int N, M, cnt=1, Res=0;
int board[1001][1001];
int vis[1001][1001];
int g[1000001];
set<int> gvis;
int BFS(int x, int y) {
    int c=0;
    queue<pair<int, int>> Q;

    Q.push({x, y});
    vis[x][y] = cnt;

    while ( !Q.empty() ) {
        pair<int, int> cur = Q.front(); Q.pop();
        c++;
        for ( int dir = 0; dir < 4; dir++ ) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if ( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
            if ( vis[nx][ny] != 0 || board[nx][ny] == 0 ) continue;

            vis[nx][ny] = cnt;
            Q.push({nx, ny});
        }
    }

    return c;
}
void GroupConnect() {
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < M; j++ ) {
            if ( board[i][j] == 0 ) {
                for ( int dir = 0; dir < 4; dir++ ) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];

                    if ( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
                    if ( vis[nx][ny] )
                        gvis.insert(vis[nx][ny]);
                }
            }

            if ( !gvis.empty() ) {
                int res = 1;
                for ( auto x : gvis )
                    res += g[x];

                gvis.clear();
                Res = max(res, Res);

                res = 0;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for ( int i = 0; i < N; i++ )
        for ( int j = 0; j < M; j++ )
            cin >> board[i][j];
    
    for ( int i = 0; i < N; i++ )
        for ( int j = 0; j < M; j++ ) { // 그룹 만들기
            if ( board[i][j] == 1 && vis[i][j] == 0 ) {
                g[cnt++] = BFS(i, j);
            }
        }

    GroupConnect();

    cout << Res;
}   