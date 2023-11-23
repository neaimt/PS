#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int N, M, A, B, S, E;
long long C, max_C=0;
vector<pair<int, long long>> arr[10001];
int vis[10001];
int BFS( long long mid ) {
  queue<int> Q;
  fill(vis, vis+N+1, 0);

  vis[S] = 1; // 시작 섬
  Q.push(S);

  while ( !Q.empty() ) {
    int cur = Q.front(); Q.pop();

    if ( cur == E ) // 목적지에 도착한다면
      return 1;

    for ( int i = 0; i < arr[cur].size(); i++ ) {
      int des = arr[cur][i].first;
      long long kg = arr[cur][i].second;
      
      if ( vis[des] || kg < mid ) continue;

      // 중량제한에 걸리지 않고 방문하지 않았다면
      vis[des] = 1;
      Q.push(des);
    }
  }

  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for ( int i = 0; i < M; i++ ) {
    cin >> A >> B >> C;
    max_C = max(max_C, C);
    arr[A].push_back({B, C});
    arr[B].push_back({A, C});
  }

  cin >> S >> E;

  long long st=1, en=max_C, result=1, ck=0;
  while ( st <= en ) {
    long long mid = ( st + en ) / 2;

    ck = BFS(mid);
    if ( ck == 1 ) {
      result = mid;
      st = mid + 1;
    }
    else 
      en = mid - 1;
  }
  cout << result;
}