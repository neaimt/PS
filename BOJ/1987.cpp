#include <iostream>
#include <algorithm>
using namespace std;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int vis[30];
string arr[21];
int R, C, res;
void backtraking(int x, int y, int cnt) {
    for ( int dir = 0; dir < 4; dir++ ) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if ( nx < 0 || nx >= R || ny < 0 || ny >= C ) continue;
        if ( vis[arr[nx][ny]-65] == 1 ) continue;

        vis[arr[nx][ny]-65] = 1;
        backtraking(nx, ny, cnt+1);
        vis[arr[nx][ny]-65] = 0;
    }

    if ( res >= 26 )
        return;

    res = max(res, cnt);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    for ( int i = 0; i < R; i++ )
        cin >> arr[i];
    
    vis[arr[0][0]-65] = 1;
    backtraking(0, 0, 1);
    cout << res;
}