#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[1001][1001];
int vis[1001][1001], ans[1001][1001];
int N, M, cnt;
int znum=1;
vector<int> Zero={};
void BFS(int a, int b) {
    queue<pair<int, int>> Q;

    Q.push({a, b});
    vis[a][b] = znum;
    cnt = 0;

    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        cnt++;
        
        for ( int dir = 0; dir < 4; dir++ ) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if ( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
            if ( board[nx][ny] || vis[nx][ny] ) continue;

            Q.push({nx, ny});
            vis[nx][ny] = znum;
        }
    }
    
    Zero.push_back(cnt); // znum 인덱스에 0 영역크기 넣어줌
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for ( int i = 0; i < N; i++ ) {
        string str;
        cin >> str;
        for ( int j = 0; j < M; j++ )
            board[i][j] = str[j] -'0';
    }
    Zero.push_back(0);
    for ( int i = 0; i < N; i++ )
        for ( int j = 0; j < M; j++ ) 
            if ( board[i][j] == 0 && vis[i][j] == 0 ) {
                BFS(i, j);
                znum++;
            }

    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < M; j++ ) {
            if ( board[i][j] == 0 ) continue;
            set<int> s;
            ans[i][j] = 1;
            for ( int dir = 0; dir < 4; dir++ ) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];

                if ( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
                if ( board[nx][ny] == 0 ) {
                    s.insert(vis[nx][ny]);
                }
            }

            for ( auto a : s )
                ans[i][j] += Zero[a];

            ans[i][j] = ans[i][j] % 10;

            s.clear();
        }
    }

    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < M; j++ ) {
            cout << ans[i][j];
        }
        cout << "\n";
    }
      
}

