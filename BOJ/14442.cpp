#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
int board[1001][1001];
int vis[1001][1001][10];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int N, M, K;
int BFS() {
    queue<pair<pair<int, int>, pair<int, int>>> Q;
    vis[0][0][0] = 1;
    Q.push({{0, 0}, {0, 1}});

    while (!Q.empty()) {
        int x = Q.front().X.X;
        int y = Q.front().X.Y;
        int B = Q.front().Y.X;
        int cnt = Q.front().Y.Y;
        Q.pop();
       
        if ( x == N-1 && y == M-1 )
            return cnt;

        for ( int dir = 0; dir < 4; dir++ ) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if ( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;

            if ( board[nx][ny] == 1 && B < K ) { // 벽이 있고, 벽 부수기가 가능하다면
                if ( vis[nx][ny][B+1] ) continue;
                Q.push({{nx, ny}, {B+1, cnt+1}});
                vis[nx][ny][B+1] = 1;
            }
            else if ( board[nx][ny] == 0 && vis[nx][ny][B] == 0 ) { // 벽이 없고, 방문 표시가 없다면
                Q.push({{nx, ny}, {B, cnt+1}});
                vis[nx][ny][B] = 1;
            }
        }
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for ( int i = 0; i < N; i++ ){
        string str;
        cin >> str;
        for ( int j = 0; j < M; j++ ) {
            int tmp = str[j]-'0';
            board[i][j] = tmp;
        }
    }
    cout << BFS();
    

    
}