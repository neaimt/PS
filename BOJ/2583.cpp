#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
int board[101][101];
int vis[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int se[4];
int N, M, K;
vector<int> Cnt;
void Input(pair<int, int> a, pair<int, int> b ) {
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < M; j++ ) { 
            if ( i >= a.X && i <= b.X && j >= a.Y && j <= b.Y ) {
                board[i][j] = 1;
            }
        }
    }
}
void BFS() {
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < M; j++ ) {
            if ( board[i][j] == 1 || vis[i][j] ) continue;
            queue<pair<int, int>> Q;
            int cnt = 1;
            Q.push({i, j});
            vis[i][j] = 1;

            while (!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();
                for ( int dir = 0; dir < 4; dir++ ) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if ( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
                    if ( board[nx][ny] || vis[nx][ny] ) continue;

                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                    cnt++;
                }
            }
            Cnt.push_back(cnt);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N >> K;
    for ( int i = 0; i < K; i++ ) {
        for ( int j = 0; j < 4; j++ )
            cin >> se[j];

        Input(make_pair(se[0], se[1]), make_pair(se[2]-1, se[3]-1));
    }
    
    BFS();

    int size = Cnt.size();
    sort(Cnt.begin(), Cnt.end());

    cout << size << "\n";
    for ( int i = 0; i < size; i++ ) {
        cout << Cnt[i] << " ";
    }
        
}
