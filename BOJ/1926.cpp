#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502];
bool vis[502][502];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m; // n, m 입력
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < m; j++ )
            cin >> board[i][j]; // 그림의 정보 입력

    int mx = 0; // 그림의 넓이 최대값
    int e = 0;
    int num = 0; // 그림의 개수
    
    //1. 그림이 그려진 첫번째 칸 찾기 + 방문 표시 + push
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < m; j++ ) {
            if ( board[i][j] == 0 || vis[i][j] == 1 ) continue;
            vis[i][j] = 1; // 방문표시
            queue<pair<int, int>> Q;
            Q.push({i, j}); // push
            num++; // 그림 개수 
            
            while(!Q.empty()) {
                e++; // 그림의 넓이
                pair<int, int> cur = Q.front(); Q.pop();
                for ( int dir = 0; dir < 4; dir++ ) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if ( nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
                    if ( board[nx][ny] != 1 || vis[nx][ny] ) continue;

                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            if ( e > mx ) mx = e; e = 0;
        }
    }

    cout << num << '\n' << mx;   
}
