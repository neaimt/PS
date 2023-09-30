#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first 
#define Y second 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
string board[101];
int vis[101][101];
int N, cnt, rg = 0;
void BFS() {
    queue<pair<int, int>> Q;
    for ( int i = 0; i < N; i++ ) 
        for ( int j = 0; j < N; j++ )
            vis[i][j] = 0;
    cnt = 0;

    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ ) {
            if ( vis[i][j] ) continue;
            Q.push({i, j});
            vis[i][j] = 1;
            cnt++;

            while(!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();

                for ( int dir = 0; dir < 4; dir++ ) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if ( nx < 0 || nx >= N || ny < 0 || ny >= N ) continue;
                    if ( vis[nx][ny] ) continue;

                    if ( rg == 0 ) {
                        if ( board[cur.X][cur.Y] == board[nx][ny] ) {
                            Q.push({nx, ny});
                            vis[nx][ny] = 1;
                        }
                    }
                    if ( rg == 1 ) {
                        if ( board[cur.X][cur.Y] == 'B' && board[nx][ny] == 'B' ) { //상관없는 색
                            Q.push({nx, ny});
                            vis[nx][ny] = 1;
                        }
                        else if ( board[cur.X][cur.Y] != 'B' && board[nx][ny] != 'B' ) { // G, R일 때
                            Q.push({nx, ny});
                            vis[nx][ny] = 1;
                        }
                    }
                }
            }
        }
    }

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for ( int i = 0; i < N; i++ )
        cin >> board[i];
    
    BFS();
    cout << cnt << " ";
    rg = 1;
    BFS();
    cout << cnt;
}
