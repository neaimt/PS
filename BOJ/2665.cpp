#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define X first
#define Y second
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
string board[51];
int vis[51][51];
int n;
void BFS() {
    queue<pair<int, int>> Q;

    vis[0][0] = 0;
    Q.push({0, 0});

    while(!Q.empty()) {
        int x = Q.front().X;
        int y = Q.front().Y;
        Q.pop();

        for ( int dir = 0; dir < 4; dir++ ) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if ( nx < 0 || nx >= n || ny < 0 || ny >= n ) continue;

            int tmp = 1-(int)(board[nx][ny]-'0');

            if ( vis[nx][ny] > vis[x][y] + tmp ) {
                vis[nx][ny] = vis[x][y] + tmp;
                Q.push({nx, ny});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for ( int i = 0; i < n; i++ ) 
        cin >> board[i];
    
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < n; j++ ) 
            vis[i][j] = 2500;

    BFS();
    cout << vis[n-1][n-1];
}