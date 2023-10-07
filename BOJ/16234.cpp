#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define X first
#define Y second
int board[51][51];
int vis[51][51], ckOpen[51][51];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int L, R, N, cnt=0;
int haveToMove() {
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ )
            if ( ckOpen[i][j] ) 
                return 1;
    }
    return 0;
}
void movePopulation(int i, int j) {
    queue<pair<int, int>> Q;
    queue<pair<int, int>> moveQ;

    int area = 1;
    int areaNum = ckOpen[i][j];
    int totalPopulation = board[i][j];
    vis[i][j] = 1;
    Q.push({i, j});
    moveQ.push({i, j});

    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for ( int dir = 0; dir < 4; dir++ ) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if ( nx < 0 || nx >= N || ny < 0 || ny >= N ) continue;
            if ( ckOpen[nx][ny] != areaNum || !ckOpen[nx][ny] || vis[nx][ny] ) continue;

            vis[nx][ny] = 1;
            area++;
            totalPopulation += board[nx][ny];
            Q.push({nx, ny});
            moveQ.push({nx, ny});
        }
    }

    int Population = totalPopulation / area;
    while (!moveQ.empty()) {
        pair<int, int> cur = moveQ.front(); moveQ.pop();
        board[cur.X][cur.Y] = Population;
    }
}
void OpenLine() {
    queue<pair<int, int>> Q;
    int areaNum = 0;

    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ ) {
            if ( vis[i][j] ) continue;
            areaNum++;
            vis[i][j] = 1;
            Q.push({i,j});

            while (!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();

                for ( int dir = 0; dir < 4; dir++ ) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if ( nx < 0 || nx >= N || ny < 0 || ny >= N ) continue;
                    if ( vis[nx][ny] ) continue;
                    int diff = abs(board[cur.X][cur.Y]-board[nx][ny]);
                    if ( diff < L || diff > R ) continue;

                    vis[nx][ny] = 1;
                    ckOpen[cur.X][cur.Y] = ckOpen[nx][ny] = areaNum;
                    Q.push({nx, ny});
                }
            }
        }
    }
}
void Moveto() {
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ ) {
            if ( !ckOpen[i][j] || vis[i][j] ) continue;
            movePopulation(i, j);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L >> R;
    for ( int i = 0; i < N; i++ )
        for ( int j = 0; j < N; j++ )
            cin >> board[i][j];

    while(1) {
        memset(vis, 0, sizeof(vis));
        memset(ckOpen, 0, sizeof(ckOpen));

        OpenLine();
        memset(vis, 0, sizeof(vis));

        if ( !haveToMove() ) break;
        Moveto();
        cnt++;
    }

    cout << cnt;
}