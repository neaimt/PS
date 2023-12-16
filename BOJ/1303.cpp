#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
#define X first
#define Y second
int N, M, Wcnt, Bcnt;
string arr[101];
int vis[101][101];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int BFS(int x, int y, char ch) {
  queue<pair<int, int>> Q;
  vis[x][y] = 1;
  Q.push({x, y});

  int cnt = 0;
  while (!Q.empty()) {
    pair<int, int> cur = Q.front(); Q.pop();
    cnt++;
    for ( int dir = 0; dir < 4; dir++ ) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if ( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
      if ( vis[nx][ny] || arr[nx][ny] != ch ) continue;

      vis[nx][ny] = 1;
      Q.push({nx, ny});
    }
  }
  return cnt;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> M >> N;
  for ( int i = 0; i < N; i++ ) cin >> arr[i];
  
  for ( int i = 0; i < N; i++ )
    for ( int j = 0; j < M; j++ )
      if ( arr[i][j] == 'W' && !vis[i][j] ) 
        Wcnt += pow(BFS(i, j, 'W'), 2);

  memset(vis, 0, sizeof(vis));
  for ( int i = 0; i < N; i++ )
    for ( int j = 0; j < M; j++ )
      if ( arr[i][j] == 'B' && !vis[i][j] ) 
        Bcnt += pow(BFS(i, j, 'B'), 2);
    
  cout << Wcnt << ' ' << Bcnt;
}