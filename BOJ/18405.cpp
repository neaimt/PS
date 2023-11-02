#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define X first
#define Y second
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int N, K, S, X, Y, m=0;
int map[201][1001];
int vis[201][1001];
vector<pair<int, int>> num[10001];
void BFS() {
    queue<pair<int, int>> Q;
    
    for ( int i = 1; i <= K; i++ ) // 작은 수부터 차례대로 큐에 넣기
        for ( int j = 0; j < num[i].size(); j++ ) {
            Q.push({num[i][j].X, num[i][j].Y});
            vis[num[i][j].X][num[i][j].Y] = i;
        }
    
    for ( int i = 0; i < S-1; i++ ) {
        while(!Q.empty()) {
            pair<int, int> cur = Q.front(); Q.pop();
            for ( int dir = 0; dir < 4; dir++ ) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if ( nx < 0 || nx >= N || ny < 0 || ny >= K ) continue;
                if ( vis[nx][ny] || map[nx][ny] ) continue;

                vis[nx][ny] = vis[cur.X][cur.Y];
                Q.push({nx, ny});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for ( int i = 0; i < N; i++ ) 
        for ( int j = 0; j < N; j++ ) {
            cin >> map[i][j];
            if ( map[i][j] )
                num[map[i][j]].push_back({i, j});
        }
    cin >> S >> X >> Y;
    BFS();

    cout << vis[X-1][Y-1];
}
