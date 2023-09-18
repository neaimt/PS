#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second
int board[1001][1001];
int day[1001][1001];
int M, N, ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    queue<pair<int, int>> Q;

    for ( int i = 0; i < N; i++ ) 
        for ( int j = 0; j < M; j++ )
            cin >> board[i][j];

    for ( int i = 0; i < N; i++ )
        for ( int j = 0; j < M; j++ ) {
            if ( board[i][j] == 1 )
                Q.push({i, j});
            else if ( board[i][j] == 0 )
                day[i][j] = -1;
        }

    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for ( int dir = 0; dir < 4; dir++ ) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if ( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
            if ( day[nx][ny] >= 0 ) continue;
            day[nx][ny] = day[cur.X][cur.Y] + 1;
            Q.push({nx, ny});        
        }
    }

    
 
    for ( int i = 0; i < N; i++ ){
        for ( int j = 0; j < M; j++ ) {
            if ( day[i][j] == -1 ) {
                cout << -1;
                return 0;
            }
            ans = max(ans, day[i][j]);
        }
    }
    cout << ans;
   
}

