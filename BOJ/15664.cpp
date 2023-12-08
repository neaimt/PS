#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, xx;
int isused[10];
int arr[10], res[10];
void func(int cnt, int cur) {
  if ( cnt == M ) {
    for ( int i = 0; i < M; i++ )
      cout << res[i] << ' ';

    cout << '\n';
    return;
  }

  int xx= 0;
  for ( int i = cur; i < N; i++ ) {
    if ( !isused[i] && arr[i] != xx ) {
      isused[i] = 1;
      res[cnt] = arr[i];
      xx = res[cnt];
      func(cnt+1, i+1);
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