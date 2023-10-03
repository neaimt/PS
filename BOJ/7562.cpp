#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
int vis[301][301];
int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int T, N;
pair<int, int> s, e;
int BFS() {
    queue<pair<int, int>> Q;

    for ( int i = 0; i < N; i++ )
        for ( int j = 0; j < N; j++ )   
            vis[i][j] = -1;

    Q.push({s.X, s.Y});
    vis[s.X][s.Y] = 0;

    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        if ( cur.X == e.X && cur.Y == e.Y )
                return vis[cur.X][cur.Y];

        for ( int dir = 0; dir < 8; dir++ ) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if ( nx < 0 || nx >= N || ny < 0 || ny >= N ) continue;

            if ( vis[nx][ny] >= 0 ) continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for ( int i = 0; i < T; i++ ) {
        cin >> N;
        cin >> s.X >> s.Y;
        cin >> e.X >> e.Y;
        cout << BFS() << "\n";
    }
}