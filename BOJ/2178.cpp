#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second
string board[102];
bool vis[102][102];
int cnt[102][102];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m, ck = 0;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for ( int i = 0; i < n; i++ )
        cin >> board[i]; // 배열 입력
    
    queue<pair<int, int>> Q;
    vis[0][0] = 1; // 첫번째 칸 방문표시
    cnt[0][0] = 1;
    Q.push({0, 0}); 

    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for ( int dir = 0; dir < 4; dir++ ) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if ( nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
            if ( vis[nx][ny] || board[nx][ny] != '1' ) continue;
            
            vis[nx][ny] = 1;
            cnt[nx][ny] = cnt[cur.X][cur.Y]+1;
            Q.push({nx, ny});
        }
    }
            
    cout << cnt[n-1][m-1];

}