#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first 
#define Y second
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int R, C, cnt=0, scnt=0, wcnt=0, o=0, v=0;
string board[252];
int vis[252][252];
void BFS() {
    queue<pair<int, int>> Q;

    for ( int i = 0; i < R; i++ ) {
        for ( int j = 0; j < C; j++ ) {
            if ( board[i][j] == '#' || vis[i][j] ) continue;
            cnt++;
            vis[i][j] = cnt;
            Q.push({i, j});
            o = 0, v = 0;
            if ( board[i][j] == 'o' ) o++;
            else if ( board[i][j] =='v' ) v++;

            while(!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();
                
                for ( int dir = 0; dir < 4; dir++ ) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if ( nx < 0 || nx >= R || ny < 0 || ny >= C ) continue;
                    if ( board[nx][ny] == '#' || vis[nx][ny] ) continue;
                    if ( board[nx][ny] == 'o' ) o++;
                    else if ( board[nx][ny] =='v' ) v++;

                    vis[nx][ny] = cnt;
                    Q.push({nx, ny});
                }
            }
            if ( o > v ) wcnt -= v;
            else scnt -= o;
        }
    }
}
void Ck() {
    for ( int i = 0; i < R; i++ ) {
        for ( int j = 0; j < C ; j++ ) {
            if ( board[i][j] == 'o') scnt++;
            else if ( board[i][j] == 'v' ) wcnt++;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++ )
        cin >> board[i];

    Ck();
    BFS();
    cout << scnt << " " << wcnt;
}