#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, a, b, ck=0;
int vis[2001];
vector<int> arr[2001];
void DFS(int cnt, int cur) { // 0부터 시작
  if ( cnt == 4 ) {
    ck = 1;
    return;
  }

  for ( int i = 0; i < arr[cur].size(); i++ ) {
    if ( !vis[arr[cur][i]] ) {
      vis[arr[cur][i]] = 1;
      DFS(cnt+1, arr[cur][i]);
      vis[arr[cur][i]] = 0;
    }
  }

  return; // cnt를 채우지 못함
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for ( int i = 0; i < M; i++ ) {
    cin >> a >> b;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }
  for ( int i = 0; i < N; i++ ) {
    fill(vis, vis+N, 0);
    vis[i] = 1;
    DFS(0, i);
    if ( ck == 1 ) break;
  }
  cout << ck;
}