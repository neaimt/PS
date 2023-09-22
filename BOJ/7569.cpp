#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int board[101][101][101];
int vis[101][101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dz[2] = {1, -1};
int N, M, H, result=0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N >> H;
    for ( int i = 0; i < H; i++ )
        for ( int j = 0; j < N; j++ )
            for ( int k = 0; k < M; k++ ) 
                cin >> board[i][j][k];

    queue<tuple<int, int, int>> Q; // tuple 은 세쌍값을 묶음
    fill(&vis[0][0][0], &vis[H][N][M], -1 );

    for ( int i = 0; i < H; i++ )
        for ( int j = 0; j < N; j++ )
            for ( int k = 0; k < M; k++ ) {
                if ( board[i][j][k] == 1 ) {
                    vis[i][j][k] = 1;
                    Q.push({i, j, k});
                }
                else if ( board[i][j][k] == 0 ) {
                    vis[i][j][k] = 0;
                }
            }

    while (!Q.empty()) {
        tuple<int, int, int> cur = Q.front(); Q.pop();
    
        for ( int dir = 0; dir < 4; dir++ ) {
            int nz = get<0>(cur);
            int nx = get<1>(cur) + dx[dir];
            int ny = get<2>(cur) + dy[dir];
                    
            if ( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
            if ( board[nz][nx][ny] != 0 || vis[nz][nx][ny] > 0 ) continue;
                    
            vis[nz][nx][ny] = vis[nz][get<1>(cur)][get<2>(cur)] + 1;
            Q.push({nz, nx, ny});
        }
        
        for ( int dir = 0; dir < 2; dir++ ) {
            int nz = get<0>(cur) + dz[dir];
            int nx = get<1>(cur);
            int ny = get<2>(cur);
            if ( nz >= H || nz < 0 ) continue;
            if ( board[nz][nx][ny] != 0 || vis[nz][nx][ny] > 0 ) continue;

            vis[nz][nx][ny] = vis[get<0>(cur)][nx][ny] + 1;
            Q.push({nz, nx, ny});
        }
    }


    for ( int i = 0; i < H; i++ )
        for ( int j = 0; j < N; j++ )
            for ( int k = 0; k < M; k++ ) {
                if ( vis[i][j][k] == 0 ) {
                    cout << -1;
                    return 0;
                }
                result = max(result, vis[i][j][k]);
            }

    cout << result-1;
}
