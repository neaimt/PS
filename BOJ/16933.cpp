#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
int board[1001][1001];
int vis[1001][1001][11];
int N, M, K;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int BFS() {
    queue<pair<tuple<int, int, int>, pair<int, int>>> Q; // 순서대로 x, y, B, cnt, m/n
    Q.push({{0, 0, 0}, {1, 0}});
    vis[0][0][0] = 1;

    while (!Q.empty()) {
        int x = get<0>(Q.front().X);
        int y = get<1>(Q.front().X);
        int B = get<2>(Q.front().X);
        int cnt = Q.front().Y.X;
        int day = Q.front().Y.Y;
        Q.pop();

        if ( x == N-1 && y == M-1 )
            return cnt;

        for ( int dir = 0; dir < 4; dir++ ) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if ( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
            
            if ( day == 0 ) { // 낮인 경우
                if ( board[nx][ny] == 0 && vis[nx][ny][B] == 0 ) { // 벽이 아닌 경우
                    vis[nx][ny][B] = 1;
                    Q.push({{nx, ny, B}, {cnt+1, 1}});
                }
                else if ( board[nx][ny] == 1 && B < K && vis[nx][ny][B+1] == 0 ) { // 벽인 경우
                    vis[nx][ny][B+1] = 1;
                    Q.push({{nx, ny, B+1}, {cnt+1, 1}});
                }
            }
            else { // 밤인 경우
                if ( board[nx][ny] == 0 && vis[nx][ny][B] == 0 ) { // 벽이 아닌 경우
                    vis[nx][ny][B] = 1;
                    Q.push({{nx, ny, B}, {cnt+1, 0}});
                }
                else if ( board[nx][ny] == 1 && B < K && vis[nx][ny][B+1] == 0 ) { // 벽인 경우
                    Q.push({{x, y, B}, {cnt+1, 0}});
                }
            }
        }
    }
    return -1;

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K; 
    for ( int i = 0; i < N; i++ ) {
        string str;
        cin >> str;
        for ( int j = 0; j < M; j++ ) {
            int tmp = str[j]-'0';
            board[i][j] = tmp;
        }
    }
    
    cout << BFS();
}