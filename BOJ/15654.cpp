#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int arr[10], isused[10], res[10];
void func(int cnt) {
  if ( cnt == M ) {
    for ( int i = 0; i < M; i++ )
      cout << res[i] << ' ';
    cout << '\n';
  }
  
  for ( int i = 0; i < N; i++ ) {
    if ( !isused[i] ) {
      res[cnt] = arr[i];
      isused[i] = 1;
      func(cnt+1);
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

  func(0);
}
/*
배열 정렬 사전순 증가
사용표시
*/