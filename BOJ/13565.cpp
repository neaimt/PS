#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define X first
#define Y second
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N, M;
string board[1001];
int vis[1001][1001];
void BFS() {
    queue<pair<int, int>> Q;
   
    for ( int j = 0; j < M; j++ ) {
        if ( board[0][j] == '0' ) {
            vis[0][j] = 1;
            Q.push({0, j});
        }
    }

    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
    
        for ( int dir = 0; dir < 4; dir++ ) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if ( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
            if ( board[nx][ny] != '0' || vis[nx][ny] ) continue;

            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for ( int i = 0; i < N; i++ )
        cin >> board[i];

    BFS();
    for ( int j = 0; j < M; j++ ) {
        if ( vis[N-1][j] == 1 ) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}