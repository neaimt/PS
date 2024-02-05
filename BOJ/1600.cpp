#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int hdx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int hdy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
int K, W, H;
int board[201][201];
int vis[31][201][201];
int BFS() {
    queue<pair<pair<int, int>, pair<int, int>>> Q;
    Q.push({{0, 0}, {0, K}});
    vis[0][0][0] = 1;
    
    while ( !Q.empty() ) {
        int x = Q.front().X.X;
        int y = Q.front().X.Y;
        int cnt = Q.front().Y.X;
        int k = Q.front().Y.Y;
        Q.pop();

        if ( x == H-1 && y == W-1 )
            return cnt;

        // 인접한 칸으로 이동
        for ( int dir = 0; dir < 4; dir++ ) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if ( nx < 0 || nx >= H || ny < 0 || ny >= W ) continue;
            if ( vis[k][nx][ny] == 0  && board[nx][ny] == 0 ) {
                    Q.push({{nx, ny}, {cnt+1, k}});
                    vis[k][nx][ny] = 1;
            }
        }

        // 말처럼 이동
        if ( k > 0 ) {
            for ( int dir = 0; dir < 8; dir++ ) {
                int nx = x + hdx[dir];
                int ny = y + hdy[dir];

                if ( nx < 0 || nx >= H || ny < 0 || ny >= W ) continue;
                if ( vis[k-1][nx][ny] == 0  && board[nx][ny] == 0 ) {
                    Q.push({{nx, ny}, {cnt+1, k-1}});
                    vis[k-1][nx][ny] = 1;
                }
            }
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K;
    cin >> W >> H;
    for ( int i = 0; i < H; i++ ) 
        for ( int j = 0; j < W; j++ )
            cin >> board[i][j];

    cout << BFS();
}