#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};
int vis[201][201];
int N, r, c, cnt=0, rr, cc;
int BFS() {
    queue<tuple<int, int, int>> Q;

    vis[r][c] = 1;
    Q.push({r, c, cnt});
    while(!Q.empty()) {
        int x = get<0>(Q.front()); 
        int y = get<1>(Q.front()); 
        cnt = get<2>(Q.front()); 
        Q.pop();

        if ( x == rr && y == cc ) 
            return cnt;

        for ( int dir = 0; dir < 6; dir++ ) {
            int nr = x + dx[dir];
            int nc = y + dy[dir];

            if ( nr < 0 || nr >= N || nc < 0 || nc >= N ) continue;
            if ( vis[nr][nc] ) continue;

            vis[nr][nc] = 1;
            Q.push({nr, nc, cnt+1});
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> r >> c >> rr >> cc;

    cout << BFS();
}