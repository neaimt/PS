#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
string arr[601];
int vis[601][601];
int N, M, Cnt, x, y;
void BFS() {
  queue<pair<int, int>> Q;
  Q.push({x, y});
  vis[x][y] = 1;

  while (!Q.empty()) {
    pair<int, int> cur = Q.front(); Q.pop();

    for ( int dir = 0; dir < 4; dir++ ) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if ( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
      if ( vis[nx][ny] != 0 ) continue;

      if ( arr[nx][ny] == 'P' )
        Cnt++;
      Q.push({nx, ny});
      vis[nx][ny] = 1;
    }
  }

}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for ( int i = 0; i < N; i++ ) cin >> arr[i];

  for ( int i = 0; i < N; i++ )
    for ( int j = 0; j < M; j++ ) {
      if ( arr[i][j] == 'I' ) {
        x = i;
        y = j;
      }
      else if ( arr[i][j] == 'X' )
        vis[i][j] = -1;
    }
  
  BFS();
  if ( Cnt == 0 )
    cout << "TT";
  else 
    cout << Cnt;

}