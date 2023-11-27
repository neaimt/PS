#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int arr[10], ans[10];
int vis[10];
void func(int num, int k) {
  if ( k == M ) {
    for ( int i = 0; i < M; i++ )
      cout << ans[i] << ' ';
    cout << '\n';
    return;
  }

  for ( int i = num; i < N; i++ ) {
      ans[k] = arr[i];
      func(i, k+1);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for ( int i = 0; i < N; i++ ) cin >> arr[i];
  sort(arr, arr+N);
  func(0, 0);
 
}