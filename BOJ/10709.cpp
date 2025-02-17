#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define X first
#define Y second
int dy[3] = {0, -1, 1};
int H, W;
string cloud[101];
int vis[101][101], cnt[101][101];
queue<pair<int, int>> Q;

void BFS(int x, int y) {
    Q.push({x, y});
    vis[x][y] = 1;
    cnt[x][y] = 0;

    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();

        for ( int dir = 0; dir < 3; dir++ ) { // 오른쪽, 왼쪽만 검사
            int ny = cur.Y + dy[dir];

            if ( ny < 0 || ny >= W ) continue;
            if ( cloud[cur.X][ny] == 'c' || vis[cur.X][ny] != 0 ) continue;

            if ( dy[dir] == -1 )
                cnt[cur.X][ny] = -1;
            else {
                cnt[cur.X][ny] = cnt[cur.X][cur.Y] + dy[dir];
            }
            vis[cur.X][ny] = 1;
            Q.push({cur.X, ny});
        }
    }
}
int main() {
    cin >> H >> W;

    for ( int i = 0; i < H; i++ ) cin >> cloud[i];

    memset(cnt, -1, sizeof(vis));

    for ( int i = 0; i < H; i++ ) {
        for ( int j = 0; j < W; j++ ) {
            if ( cloud[i][j] == 'c' ) {
                BFS(i, j);
            }
        }
    }

    for ( int i = 0; i < H; i++ ) {
        for ( int j = 0; j < W; j++ ) {
            cout << cnt[i][j] << ' ';
        }
        cout << '\n';
    } 
}