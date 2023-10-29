#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int board[101][101];
int vis[101][101][2]; // 그람 획득 전, 획득 후 방문표시
int N, M, T, cnt=0;
int Gx, Gy, result=0;
int BFS() {
    queue<tuple<int, int, int>> Q;
    memset(vis, -1, sizeof(vis));
    vis[1][1][0] = 0;
    vis[1][1][1] = 0;
    Q.push({1, 1, 0});

    while(!Q.empty()) {
        int x = get<0>(Q.front());
        int y = get<1>(Q.front());
        int G = get<2>(Q.front());
        Q.pop();

        if ( x == N && y == M ) 
            return vis[x][y][G];

        for ( int dir = 0; dir < 4; dir++ ) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if ( nx < 1 ||  nx > N || ny < 1 || ny > M ) continue;
            
            if ( board[nx][ny] != 1 && vis[nx][ny][0] == -1 && G == 0 ) {
                vis[nx][ny][0] = vis[x][y][0] + 1; 
                
                if ( nx == Gx && ny == Gy ) {
                    vis[nx][ny][1] = vis[x][y][0] + 1; 
                    Q.push({nx, ny, 1});
                }
                else 
                    Q.push({nx, ny, 0});
            }   

            if ( vis[nx][ny][1] == -1 && G == 1 ) {
                vis[nx][ny][1] = vis[x][y][1] + 1;
                Q.push({nx, ny, 1});
            }
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> T;
    for ( int i = 1; i <= N; i++ )
        for ( int j = 1; j <= M; j++ ) {
            cin >> board[i][j];
            if ( board[i][j] == 2 )
                Gx = i, Gy = j;
        }
    
    result = BFS();

    if ( result == -1 || result > T ) 
        cout << "Fail";
    else 
        cout << BFS(); 
}