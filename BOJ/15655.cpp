#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int arr[10], res[10];
int isused[10];
void func(int cnt, int cur) {
  if ( cnt == M ) {
    for ( int i = 0; i < M; i++ ) 
      cout << res[i] << ' ';
    cout << '\n';
    return;
  }

  for ( int i = cur; i < N; i++ ) {
    if ( !isused[i] ) {
      isused[i] = 1;
      res[cnt] = arr[i];
      func(cnt+1, i);
      isused[i] = 0;
    }
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