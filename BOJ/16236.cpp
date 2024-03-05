#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int N, SharkSize=2, res=0, eat=false, help=true;
int tmp, eatCnt=0;
int board[22][22], vis[22][22];
pair<int, int> shark;
void BFS() {
    // 방문 초기화
    fill(&vis[0][0], &vis[N][N], 0);

    queue<pair<pair<int, int>, int>> Q;
    Q.push({{shark.X, shark.Y}, 0});
    vis[shark.X][shark.Y] = 1;
    board[shark.X][shark.Y] = 0; // 먹어서 없어짐

    while ( !Q.empty() ) {
        pair<int, int> cur = Q.front().X;
        int cnt = Q.front().Y;
        Q.pop();
        
        // 우선 순위 위치
        if ( eat && board[cur.X][cur.Y] > 0 && board[cur.X][cur.Y] < SharkSize && cnt == tmp )
            if ( (cur.X < shark.X) || (cur.X == shark.X && cur.Y < shark.Y) ) // 위쪽, 왼쪽 우선순위
                shark = {cur.X, cur.Y}; // 상어 위치 수정

        for ( int dir = 0; dir < 4; dir++ ) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if ( nx < 0 || nx >= N || ny < 0 || ny >= N ) continue;
            if ( vis[nx][ny] ) continue;

            // 상어가 지나다닐 수 있는 공간
            if ( board[nx][ny] >= 0 && board[nx][ny] <= SharkSize ) {
                Q.push({{nx, ny}, cnt+1});
                vis[nx][ny] = 1;

                // 먹을 수 있는 물고기가 있는 공간
                if ( board[nx][ny] > 0 && board[nx][ny] < SharkSize && !eat ) { // 먹지 않은 상태
                    eat = true;
                    shark = {nx, ny};
                    tmp = cnt+1;
                    res += tmp;
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for ( int i = 0; i < N; i++ ) 
        for ( int j = 0; j < N; j++ ) {
            cin >> board[i][j];
            if ( board[i][j] == 9 )
                shark = {i, j};
        }

    while ( help ) {
        eat = false;
        BFS();
        if ( eat ) { // 물고기를 먹음
            eatCnt++;
            if ( eatCnt == SharkSize ) {
                SharkSize++;
                eatCnt = 0;
            }
        }
        else // 먹을 물고기가 없음
            help = false; // 엄마 부름
    }
    cout << res;
}