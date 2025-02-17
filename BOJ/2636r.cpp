#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iterator>

using namespace std;

#define X first
#define Y second
int dx[4] = {0, 1, 0, -1};
int dy[4] = { 1, 0, -1, 0};

int arr[101][101], vis[101][101];
int N, M, cnt, t, t_1_cnt;

queue<pair<int, int>> Q;

void BFS() {
    while( !Q.empty() ) {
        pair<int, int> cur = Q.front(); Q.pop();
    
        for ( int dir = 0; dir < 4; dir++ ) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if ( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
            if ( vis[nx][ny] == 1 ) continue;

            if ( arr[nx][ny] == 0 ) { // 방문하지 않은 공기
                vis[nx][ny] = 1;
                Q.push({nx, ny});
            } else {
                arr[nx][ny] = 0;
                vis[nx][ny] = 1;
           }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < M; j++ ) {
            cin >> arr[i][j];
            if ( arr[i][j] == 1 ) cnt++;
        }
    }

    while( cnt != 0 ) {
        t++;
        t_1_cnt = cnt;

        memset(vis, 0, sizeof(vis));
        for ( int i = 0; i < N; i++ ) {
            for ( int j = 0; j < M; j++ ) {
                if ( i == 0 || i == N-1 || j == 0 || j == M-1 ) {
                    Q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        BFS();

        cnt = 0;
        for ( int i = 0; i < N; i++ ) {
            cnt += count(begin(arr[i]), end(arr[i]), 1);
        }
    }

    cout << t << '\n' << t_1_cnt;
}

// 가장자리 공기를 큐에 넣음
// 방문하지 않은 공기이면 방문표시 후 큐에 넣고, 치즈일 경우 값 변경 0으로 + 방문표시 ( 큐에 넣지 않음 )
// 치즈값 세기
// 다시 BFS

