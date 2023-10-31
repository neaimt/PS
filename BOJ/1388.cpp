#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define X first
#define Y second
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
string board[51];
int vis[51][51];
int N, M, cnt = 0;
void DFS(){
    stack<pair<int, int>> S; // x, y, cnt

    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < M; j++ ) {
            if ( vis[i][j] ) continue;
            cnt++;
            vis[i][j] = cnt;
            S.push({i, j});

            while(!S.empty()) {
                pair<int, int> cur = S.top(); S.pop();

                if ( board[cur.X][cur.Y] == '-') { // 가로판자일 경우
                    for ( int dir = 0; dir < 2; dir++ ) { // 좌우만 체크
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if ( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
                        if ( vis[nx][ny] || board[nx][ny] != '-' ) continue;
                        
                        vis[nx][ny] = cnt;
                        S.push({nx, ny});
                    }
                }

                else if ( board[cur.X][cur.Y] == '|') { // 세로판자일 경우
                    for ( int dir = 2; dir < 4; dir++ ) { // 상하만 체크
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if ( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
                        if ( vis[nx][ny] || board[nx][ny] != '|' ) continue;
                        
                        vis[nx][ny] = cnt;
                        S.push({nx, ny});
                    }
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for ( int i = 0; i < N; i++ )
        cin >> board[i];
    DFS();
    cout << cnt;
}