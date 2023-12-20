#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
int R, C, Wcnt, Scnt;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
string arr[251];
int vis[251][251];
void BFS(int x, int y) {
    queue<pair<int, int>> Q;
    int wcnt=0, scnt=0;
    Q.push({x, y});
    vis[x][y] = 1;

    while ( !Q.empty() ) {
        pair<int, int> cur = Q.front(); Q.pop();
        
        if ( arr[cur.X][cur.Y] == 'v' ) wcnt++;
        else if ( arr[cur.X][cur.Y] == 'k' ) scnt++;
            
        for ( int dir = 0; dir < 4; dir++ ) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if ( nx < 0 || nx >= R || ny < 0 || ny >= C ) continue;
            if ( vis[nx][ny] || arr[nx][ny] == '#' ) continue;

            Q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }
    if ( wcnt >= scnt ) Wcnt += wcnt;
    else Scnt += scnt;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    for ( int i = 0; i < R; i++ )
        cin >> arr[i];
    
    for ( int i = 0; i < R; i++ ) {
        for ( int j = 0; j < C; j++ ) {
            if ( arr[i][j] != '#' && !vis[i][j] )
                BFS(i, j);
        }
    }

    cout << Scnt << ' ' << Wcnt;
}