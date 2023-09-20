#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
int board[9][9], board2[9][9];
int vis[9][9];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int N, M, cnt=3, Max=0;
void BFS();
void Cnt();
void wall() {
    if ( cnt == 0 )
        return BFS();

    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < M; j++ ) {
            if ( board2[i][j] == 0 ) {
                cnt--;
                board2[i][j] = 1;
                wall();
                cnt++;
                board2[i][j] = 0;    
            }
        }
    }
}
void BFS() {
    for ( int i = 0; i < N; i++ ) 
        for ( int j = 0; j < M; j++ ) {
            board[i][j] = board2[i][j];
            vis[i][j] = 0;
        }
            
    queue<pair<int, int>> Q;
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < M; j++ ) {
            if ( board[i][j] == 1 )
                vis[i][j] = 1;

            else if ( board[i][j] == 2 ) {
                Q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }

    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();

        for ( int dir = 0; dir < 4; dir++ ) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if ( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
            if ( board[nx][ny] != 0 || vis[nx][ny] ) continue;

            board[nx][ny] = 2;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
    
    Cnt();
}
void Cnt() {
    int c = 0;
    for ( int i = 0; i < N; i++ )
        for ( int j = 0; j < M; j++ )
            if ( board[i][j] == 0 )
                c++;
    
    Max = max(c, Max);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    for ( int i = 0; i < N; i++ )
        for ( int j = 0; j < M; j++ ) 
            cin >> board2[i][j];
        
    wall();
    cout << Max;
    
}

